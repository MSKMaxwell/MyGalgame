#include "savebox.h"
#include "ui_savebox.h"

SaveBox::SaveBox(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveBox)
{
    ui->setupUi(this);
}

SaveBox::~SaveBox()
{
    delete ui;
}
