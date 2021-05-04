/*
 * 导员功能界面
 * 查看目前通过成果
 * 审核成果
 * 排序
 * 导入数据
 * 2021-03-10-xsq
 */

#include "statusframe.h"
#include "ui_statusframe.h"
#include <QString>
#include <QFile>
#include "look.h"
#include "to_examine.h"
#include "QPropertyAnimation"


Statusframe::Statusframe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statusframe)
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

    //设置文字竖排显示
    ui->label_2->setText("管\n理\n员\n");
    //设置Lable文字居中
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignHCenter);

    //进入动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

Statusframe::~Statusframe()
{
    delete ui;
}

//保存 到对应文件
void Statusframe::on_pushButton_clicked()
{
    QString str=ui->textEdit->toPlainText();
    if(str=="")
    {
        ui->label_4->setText("请输入地址");
        return;
    }
    QFile f(str);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ui->label_4->setText("地址错误");
        return;
    }

    //f.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!f.atEnd())
    {
        //国家级省级科技成果奖,论文,在报刊杂志上发表作品,其它
        QByteArray line=f.readLine();
        QString str(line);
        if(str.startsWith("国家级省级科技成果奖")||str.startsWith("论文")||str.startsWith("在报刊杂志上发表作品")||str.startsWith("其它"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研成果.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }
        else if(str.startsWith("获得专利")||str.startsWith("软件著作权")||str.startsWith("其他"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\知识产权.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }
        else if(str.startsWith("科研训练"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研训练.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }else if(str.startsWith("学科与科技竞赛"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\学科与科技竞赛.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }else if(str.startsWith("技能证书"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\技能证书.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }else if(str.startsWith("创业实践和创新创业教育"))
        {
            QFile ff("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\创业实践和创新创业教育.txt");
            ff.open(QIODevice::Append|QIODevice::Text);
            ff.write(str.toUtf8()+'\n');
        }
    }
    ui->label_4->setText("导入成功");
    ui->textEdit->clear();
}

//导员查看通过数据
void Statusframe::on_pushButton_8_clicked()
{
    Look p;
    p.exec();
}


//导员审核数据
void Statusframe::on_pushButton_7_clicked()
{
    To_examine p;
    p.exec();
}
