#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private slots:
    void on_pushButton_clicked();//查找各个文件

    void sear(QString name,QString d,int color);//在文件中查找 name 同名的成果并用QTableWidget显示

    void on_pushButton_2_clicked();//关闭界面

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
