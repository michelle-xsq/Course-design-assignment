/*
 * 学生查找自己的成果
 * 通过颜色辨别是否审核
 * 2021-03-09-xsq
 */

#include "search.h"
#include "ui_search.h"
#include <QListWidget>
#include <QString>
#include <QListWidgetItem>
#include <QFile>
#include "QPropertyAnimation"

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
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

Search::~Search()
{
    delete ui;
}

void Search::sear(QString name,QString d,int color)
{

    QListWidgetItem *item;
    QFile f(d);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!f.atEnd())
    {
        QByteArray line=f.readLine();
        QString str(line);
        if(str.contains(name))
        {

            item=new QListWidgetItem;
            QFont font;
            //font.setBold(true);//设置为粗体
            font.setPointSize(11);//字体大小
            item->setFont(font);

            item->setText(str);//将对应类别和信息显示到list
            if(!color)item->setBackgroundColor(QColor("red"));//未通过显示红色背景
            else item->setBackgroundColor(QColor("green"));//通过显示绿色背景
            item->setSizeHint(QSize(100, 100));
            ui->listWidget->addItem(item);//添加一个list中的对象
        }
    }
    f.close();
}

void Search::on_pushButton_clicked()
{
    ui->listWidget->clear();
    QString name=ui->lineEdit->text();
    //审核通过
    QString d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研成果.txt";
    QString d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\知识产权.txt";
    QString d3="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研训练.txt";
    QString d4="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\学科与科技竞赛.txt";
    QString d5="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\技能证书.txt";
    QString d6="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\创业实践和创新创业教育.txt";
    sear(name,d1,1);
    sear(name,d2,1);
    sear(name,d3,1);
    sear(name,d4,1);
    sear(name,d5,1);
    sear(name,d6,1);
    //未审核
    d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
    d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
    d3="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研训练.txt";
    d4="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核学科与科技竞赛.txt";
    d5="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核技能证书.txt";
    d6="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核创业实践和创新创业教育.txt";

    sear(name,d1,0);
    sear(name,d2,0);
    sear(name,d3,0);
    sear(name,d4,0);
    sear(name,d5,0);
    sear(name,d6,0);

    if(ui->listWidget->count()==0)
    {
        QListWidgetItem *item=new QListWidgetItem;
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(15);//字体大小
        item->setFont(font);
        item->setTextAlignment(Qt::AlignHCenter);
        item->setText("未申报课外科技活动成果");
        ui->listWidget->addItem(item);
    }

}

void Search::on_pushButton_2_clicked()
{
    this->close();
}
