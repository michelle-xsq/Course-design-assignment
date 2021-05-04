/*
 * 学生个人成果提交失败界面
 * 2021-03-10-xsq
 */

#include "submit.h"
#include "ui_submit.h"
#include "QPropertyAnimation"


Submit::Submit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Submit)
{
    ui->setupUi(this);
    //设置界面标题
    setWindowTitle(QString("大学生课外科技活动成果管理系统"));

    //设置界面背景
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    QPixmap pixmap("E:\\Qt\\hello\\datastructure\\background.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    QPalette palette2=this->palette();
    palette2.setBrush(QPalette::WindowText,Qt::white);
    this->setPalette(palette2);

    //进入动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

Submit::~Submit()
{
    delete ui;
}

void Submit::on_pushButton_clicked()
{
    this->close();
}
