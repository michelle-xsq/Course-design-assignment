#ifndef CHECK_H
#define CHECK_H

#include <QDialog>

namespace Ui {
class Check;
}

class Check : public QDialog
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = 0);
    ~Check();

private slots:
    void on_pushButton_clicked();//验证权限密码

private:
    Ui::Check *ui;
};

#endif // CHECK_H
