#ifndef LOVE_H
#define LOVE_H

#include <QDialog>

namespace Ui {
class Love;
}

class Love : public QDialog
{
    Q_OBJECT

public:
    explicit Love(QWidget *parent = 0);
    ~Love();

private slots:
    void on_pushButton_clicked();//提交数据

    void on_pushButton_2_clicked();//关闭界面

private:
    Ui::Love *ui;
};

#endif // LOVE_H
