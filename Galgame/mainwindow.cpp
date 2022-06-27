#include "textprocess.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QMessageBox>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,CharaPositionSwitch(true)
{
    ui->setupUi(this);

    this->setWindowTitle("荧和心海的璃月行");

    // 游戏初始化部分
    // 创建游戏模型对象
    game = new Galgame(":/Res/Script.txt");
//    ui->label_6->setText(game->Script.CharaTalk);
//    ui->label_7->setText(game->Script.CharaName);
//    ui->label_5->setPixmap(QPixmap(":/Res/Ying.jpg"));
//    ui->label_charaleft->setPixmap(QPixmap(":/Res/Lumine.png"));

    // 主页面与其他页面之间的切换
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->actionExit,&QAction::triggered, this,&QMainWindow::close);
    connect(ui->label_4,&MyLabel::MyLabelPressed,this,&QMainWindow::close);
    connect(ui->actionMainPage,&QAction::triggered,ui->stackedWidget,[=]()
    {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->actionStart,&QAction::triggered,ui->stackedWidget,[=]()
    {
       ui->stackedWidget->setCurrentIndex(1);
       game->SetGameStatus(Galgame::GameStatus::Playing);
       PlayingUpdate();
    });
    connect(ui->label,&MyLabel::MyLabelPressed,ui->stackedWidget,[=]()
    {
       ui->stackedWidget->setCurrentIndex(1);
       game->SetGameStatus(Galgame::GameStatus::Playing);
       PlayingUpdate();
    });
    connect(ui->actionSetting,&QAction::triggered,ui->stackedWidget,[=]()
    {
        ui->stackedWidget->setCurrentIndex(2);
    });
    connect(ui->label_3,&MyLabel::MyLabelPressed,this,[=]()
    {
        ui->stackedWidget->setCurrentIndex(2);
    });
    ui->frame->setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow()
{
    delete ui;
//    delete game;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(ui->stackedWidget->currentIndex() == 1 && game->GetGameStatus() == Galgame::GameStatus::Playing)
    {
        if(event->button() == Qt::LeftButton)
        {
            PlayingUpdate();// 使用脚本控制画面
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    QPen pen(Qt::NoPen);
    p.setPen(pen);
    QBrush brush(QPixmap(":/Res/MainPageBackground.png"));
    p.setBrush(brush);
    p.drawRect(this->rect());
}

bool MainWindow::PlayingUpdate()
{
    if(game->NextTalk())
    {
        ui->label_charatalk->setText(game->Script.CharaTalk);
        ui->label_charaname->setText(game->Script.CharaName);
        ui->label_charafacepic->setPixmap(QPixmap(game->Script.CharaFacePici->second));
        if(CharaPositionSwitch)
        {
            ui->label_charaleft->setPixmap(QPixmap(game->Script.CharaPici->second));
            CharaPositionSwitch = !CharaPositionSwitch;
            return true;
        }
        else
        {
            ui->label_chararight->setPixmap((QPixmap(game->Script.CharaPici->second)));
            CharaPositionSwitch = !CharaPositionSwitch;
            return true;
        }

    }
    else
    {

        QMessageBox::information(this,"信息","剧情已到末尾！",QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::Discard);
        ui->stackedWidget->setCurrentIndex(0);
        delete game;
        game = nullptr;
        game = new Galgame(":/Res/Script.txt");
        return false;

    }
}
