#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListWidgetItem>
#define N 5
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:


    void textchange(QListWidgetItem*);//双击行后 开启编辑

    //保存科研成果文件
    void save(QString,QString str,QListWidgetItem*,QString anme,QString student_num,QString student_lel);//点击后编辑 保存到文件里


    void on_pushButton_clicked();//提交数据

    void on_radioButton_clicked();//各个类别科研成果 列表显示

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_2_clicked();//关闭界面

private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
