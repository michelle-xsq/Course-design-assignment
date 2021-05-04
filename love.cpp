/*
 * 报错
 * 将用户提出的意见保存到文件
 * 2021-03-14-xsq
 */

#include "love.h"
#include "ui_love.h"
#include "QPropertyAnimation"
#include "QString"
#include "QFile"

Love::Love(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Love)
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
}

Love::~Love()
{
    delete ui;
}

//提交错误学号报错 保存学号
void Love::on_pushButton_clicked()
{
    QString number=ui->textEdit->toPlainText();
    QFile f("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\报错.txt");
    f.open(QIODevice::Append | QIODevice::Text);
    f.write(number.toUtf8()+'\n');
    f.close();
    this->close();
}

//关闭界面


void Love::on_pushButton_2_clicked()
{
    this->close();
}
