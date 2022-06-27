#include "mylabel.h"
#include <QMouseEvent>
#include "ui_mylabel.h"

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent),
    ui(new Ui::MyLabel)
{
    ui->setupUi(this);
}

MyLabel::~MyLabel()
{
    delete ui;
}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        emit MyLabelPressed();
    }
}
