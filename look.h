#ifndef LOOK_H
#define LOOK_H

#include <QDialog>

namespace Ui {
class Look;
}

class Look : public QDialog
{
    Q_OBJECT

public:
    explicit Look(QWidget *parent = 0);
    ~Look();
    void search_txt(QString);//将QString地址文件显示table

private slots:
    void on_pushButton_clicked();//关闭界面

    void on_pushButton_10_clicked();//六个类别成果查看

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void sort(int);//表头排序

private:
    Ui::Look *ui;
};

#endif // LOOK_H
