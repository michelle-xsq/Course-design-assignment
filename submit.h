#ifndef SUBMIT_H
#define SUBMIT_H

#include <QDialog>

namespace Ui {
class Submit;
}

class Submit : public QDialog
{
    Q_OBJECT

public:
    explicit Submit(QWidget *parent = 0);
    ~Submit();

private slots:
    void on_pushButton_clicked();//关闭界面

private:
    Ui::Submit *ui;
};

#endif // SUBMIT_H
