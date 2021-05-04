/*
 * 权限界面
 * 阔以就此进入管理员界面
 * 2021-03-10-xsq
 */

#include "ui_check.h"
#include "statusframe.h"
#include "check.h"
#include "QPropertyAnimation"
Check::Check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);
    //设置界面标题
    setWindowTitle(QString("大学生课外科技活动成果管理系统"));
    //设置界面图标
    setWindowIcon(QIcon("E:\\Qt\\hello\\datastructure\\wust.jpg"));
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
    ui->lineEdit->setEchoMode(QLineEdit::Password);

}

Check::~Check()
{
    delete ui;
}


void Check::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text();
    if(str=="123456")
    {
        this->close();
        Statusframe p;
        p.exec();
    }else
    {
        ui->label_2->setText("权限密码错误");
        ui->lineEdit->clear();
    }
}
