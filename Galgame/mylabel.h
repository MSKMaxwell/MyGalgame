#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QWidget>

namespace Ui {
class MyLabel;
}

class MyLabel : public QLabel
{
    Q_OBJECT

public:
    explicit MyLabel(QWidget *parent = nullptr);
    ~MyLabel();

private:
    Ui::MyLabel *ui;

protected:
    virtual void mousePressEvent(QMouseEvent *event);

signals:
    void MyLabelPressed();
};

#endif // MYLABEL_H
