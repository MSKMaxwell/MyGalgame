#ifndef SAVEBOX_H
#define SAVEBOX_H

#include <QWidget>

namespace Ui {
class SaveBox;
}

class SaveBox : public QWidget
{
    Q_OBJECT

public:
    explicit SaveBox(QWidget *parent = nullptr);
    ~SaveBox();

private:
    Ui::SaveBox *ui;

signals:
    void nowlinenum_toRead(int);
};

#endif // SAVEBOX_H
