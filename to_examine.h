#ifndef TO_EXAMINE_H
#define TO_EXAMINE_H

#include <QDialog>
#include <QString>

namespace Ui {
class To_examine;
}

class To_examine : public QDialog
{
    Q_OBJECT

public:
    explicit To_examine(QWidget *parent = 0);
    ~To_examine();
    void open_txt(QString);//具体每行数据显示
    void qing();//清空列表


private slots:
    void on_pushButton_clicked();//取消界面

    void on_pushButton_11_clicked();

    void sort(int);//排序

    void on_pushButton_14_clicked();//审核

    void on_pushButton_8_clicked();//六个类别

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_2_clicked();//关闭界面

private:
    Ui::To_examine *ui;
};

#endif // TO_EXAMINE_H
