/*
 * 学生个人提交成果界面
 * 以listwidget表形式收集信息 保存到到未审核文件中
 * 导员打开这些文件进行审核
 * 一次只可提交一个成果
 * 2021-03-08-xsq
 */

#include "dialog.h"
#include "ui_dialog.h"
#include <QListWidget>
#include <QListWidgetItem>
#include <QFile>
#include <QString>
#include <QRadioButton>
#include "submit.h"
#include "QPropertyAnimation"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
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

Dialog::~Dialog()
{
    delete ui;
}

//编辑对应条目
void Dialog::textchange(QListWidgetItem* item)
{

    QString str=item->text();
    item->setFlags(item->flags()|Qt::ItemIsEditable);
    ui->listWidget->setEditTriggers(QAbstractItemView::DoubleClicked);

}

//将提交的数据科研成果1保存到文件
void Dialog::save(QString d,QString sstr,QListWidgetItem *item,QString name,QString student_num,QString student_lel)
{
    QString str=item->text();
    QFile f(d);
    f.open(QIODevice::Append | QIODevice::Text);
    f.write(sstr.toUtf8()+' '+name.toUtf8()+' '+student_num.toUtf8()+' '+student_lel.toUtf8()+' '+str.toUtf8()+'\n');
    f.close();
}



//提交数据到txt中
void Dialog::on_pushButton_clicked()
{
    //将改变的数据加入 对应txt文件中
    if (ui->radioButton->isChecked())
    {
        int c=0;
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem* item=ui->listWidget->item(i);
            QString str=item->text();
            if(i==0&&str!="获得的国家级、省级科技成果奖")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
                save(d,"获得的国家级、省级科技成果奖",item,name,student_num,student_lel);
            }else if(i==1&&str!="在公开出版的学术期刊上发表的论文以及被省级以上学术会议收录的论文")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
                save(d,"论文",item,name,student_num,student_lel);
            }
            else if(i==2&&str!="在报刊、杂志上发表作品")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
                save(d,"在报刊、杂志上发表作品",item,name,student_num,student_lel);
            }
            else if(i==3&&str!="其它")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
                save(d,"其它",item,name,student_num,student_lel);
            }
        }
        if(c==0)
        {
            Submit p;
            p.exec();
        }
    }
    else if(ui->radioButton_2->isChecked())
    {
        int c=0;
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem* item=ui->listWidget->item(i);
            QString str=item->text();
            if(i==0&&str!="获得专利")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
                save(d,"获得专利",item,name,student_num,student_lel);
            }else if(i==1&&str!="软件著作权")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
                save(d,"软件著作权",item,name,student_num,student_lel);
            }
            else if(i==2&&str!="其他")
            {
                c++;
                QString name=ui->lineEdit->text();
                QString student_num=ui->lineEdit_2->text();
                QString student_lel=ui->lineEdit_3->text();
                QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
                save(d,"其它",item,name,student_num,student_lel);
            }
        }
        if(c==0)
        {
            Submit p;
            p.exec();
        }
    }else if(ui->radioButton_3->isChecked())
    {

        QString name=ui->lineEdit->text();
        QString student_num=ui->lineEdit_2->text();
        QString student_lel=ui->lineEdit_3->text();
        QString strict_name,strict_time,add;
        int flag=1;//标志是否合法
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem *item=ui->listWidget->item(i);
            QString s=item->text();
            if(i==0)
            {
                if(s!="参加训练名称")strict_name=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==1)
            {
                if(s!="时间")strict_time=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==2)
            {
                if(s=="备注")add="无备注";
                else add=s;
            }
        }
        if(flag)
        {
            QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研训练.txt",nn="科研训练";
            QFile f(d);
            f.open(QIODevice::Append | QIODevice::Text);
            f.write(nn.toUtf8()+' '+name.toUtf8()+' '+student_num.toUtf8()+' '+student_lel.toUtf8()+' '+strict_name.toUtf8()+' '+strict_time.toUtf8()+' '+add.toUtf8()+'\n');
            f.close();
        }
    }else if(ui->radioButton_4->isChecked())
    {
        //"竞赛名称","级别","获奖名次","时间","学分值"
        QString name=ui->lineEdit->text();
        QString student_num=ui->lineEdit_2->text();
        QString student_lel=ui->lineEdit_3->text();
        QString con_name,con_grade,con_order,con_time,con_score;
        int flag=1;//标志是否合法
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem *item=ui->listWidget->item(i);
            QString s=item->text();
            if(i==0)
            {
                if(s!="竞赛名称")con_name=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==1)
            {
                if(s!="级别")con_grade=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==2)
            {
                if(s!="获奖名次")con_order=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==3)
            {
                if(s!="时间")con_time=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==4)
            {
                if(s!="学分值")con_score=s;
                else
                {
                    Submit p;
                    p.exec();
                    break;
                }
            }
        }
        if(flag)
        {
            QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核学科与科技竞赛.txt",nn="学科与科技竞赛";
            QFile f(d);
            f.open(QIODevice::Append | QIODevice::Text);
            f.write(nn.toUtf8()+' '+name.toUtf8()+' '+student_num.toUtf8()+' '+student_lel.toUtf8()+' ');
            f.write(con_name.toUtf8()+' '+con_grade.toUtf8()+' '+con_order.toUtf8()+' '+con_time.toUtf8()+' '+con_score.toUtf8()+'\n');
            f.close();
        }
    }else if(ui->radioButton_5->isChecked())
    {
        //"证书名称","获得时间","编号(有则填)"
        QString name=ui->lineEdit->text();
        QString student_num=ui->lineEdit_2->text();
        QString student_lel=ui->lineEdit_3->text();
        QString cred_name,cred_time,cred_num;
        int flag=1;//标志是否合法
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem *item=ui->listWidget->item(i);
            QString s=item->text();
            if(i==0)
            {
                if(s!="证书名称")cred_name=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }

            }
            if(i==1)
            {
                if(s!="获得时间")cred_time=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;

                }
            }
            if(i==2)
            {
                if(s=="编号(有则填)")cred_num="无编号";
                else cred_num=s;
            }
        }
        if(flag)
        {
            QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核技能证书.txt",nn="技能证书";
            QFile f(d);
            f.open(QIODevice::Append | QIODevice::Text);
            f.write(nn.toUtf8()+' '+name.toUtf8()+' '+student_num.toUtf8()+' '+student_lel.toUtf8()+' ');
            f.write(cred_name.toUtf8()+' '+cred_time.toUtf8()+' '+cred_num.toUtf8()+'\n');
            f.close();
        }
    }else if(ui->radioButton_6->isChecked())
    {
        //"参加创业实践或创新创业教育名称","参加时间","是否有证书"
        QString name=ui->lineEdit->text();
        QString student_num=ui->lineEdit_2->text();
        QString student_lel=ui->lineEdit_3->text();
        QString ed_name,ed_time,is_ed_cerf;
        int flag=1;//标志是否合法
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem *item=ui->listWidget->item(i);
            QString s=item->text();
            if(i==0)
            {
                if(s!="参加创业实践或创新创业教育名称")ed_name=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==1)
            {
                if(s!="参加时间")ed_time=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
            if(i==2)
            {
                if(s!="是否有证书")is_ed_cerf=s;
                else
                {
                    flag=0;
                    Submit p;
                    p.exec();
                    break;
                }
            }
        }
        if(flag)
        {
            QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核创业实践和创新创业教育.txt",nn="创业实践和创新创业教育";
            QFile f(d);
            f.open(QIODevice::Append | QIODevice::Text);
            f.write(nn.toUtf8()+' '+name.toUtf8()+' '+student_num.toUtf8()+' '+student_lel.toUtf8()+' ');
            f.write(ed_name.toUtf8()+' '+ed_time.toUtf8()+' '+is_ed_cerf.toUtf8()+'\n');
            f.close();
        }
    }
    //关闭界面
    this->close();
}

//科研成果
void Dialog::on_radioButton_clicked()
{
    ui->listWidget->clear();

    //添加标题 科研成果分类
    QListWidgetItem* headerItem;
    QString a[4]={"获得的国家级、省级科技成果奖","在公开出版的学术期刊上发表的论文以及被省级以上学术会议收录的论文","在报刊、杂志上发表作品","其它"};
    for(int i=0;i<4;i++)
    {
        headerItem=new QListWidgetItem;
        headerItem->setSizeHint(QSize(200, 60));
        headerItem->setText(a[i]);
        ui->listWidget->addItem(headerItem);
    }

    headerItem=new QListWidgetItem;
    headerItem->setText("若是论文请依次填写论文名称、作者、排序、刊物名称、发表年月、收录情况、学分值等等");
    headerItem->setSizeHint(QSize(200, 60));
    ui->listWidget->addItem(headerItem);

    headerItem=new QListWidgetItem;
    headerItem->setText("最好写完整信息");
    headerItem->setSizeHint(QSize(200, 60));
    ui->listWidget->addItem(headerItem);

    if(ui->listWidget->currentRow()<4)connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));

}

//知识产权
void Dialog::on_radioButton_2_clicked()
{
    ui->listWidget->clear();

    //添加标题
    QListWidgetItem* headerItem;
    QString a[4]={"获得专利","软件著作权","其他"};
    for(int i=0;i<3;i++)
    {
        headerItem=new QListWidgetItem;
        headerItem->setSizeHint(QSize(200, 60));
        headerItem->setText(a[i]);
        ui->listWidget->addItem(headerItem);
    }

    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));

}

//科研训练
void Dialog::on_radioButton_3_clicked()
{
    ui->listWidget->clear();

    //添加标题
    QListWidgetItem* headerItem;
    QString a("参加训练名称"),b("时间"),c("备注");
    headerItem=new QListWidgetItem;
    headerItem->setText(a);
    headerItem->setSizeHint(QSize(200, 60));
    ui->listWidget->addItem(headerItem);

    headerItem=new QListWidgetItem;
    headerItem->setSizeHint(QSize(200, 60));
    headerItem->setText(b);
    ui->listWidget->addItem(headerItem);

    headerItem=new QListWidgetItem;
    headerItem->setText(c);
    headerItem->setSizeHint(QSize(200, 60));
    ui->listWidget->addItem(headerItem);

    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));

}

//学科与科技竞赛
void Dialog::on_radioButton_4_clicked()
{
    ui->listWidget->clear();

    //添加标题
    QListWidgetItem* headerItem;
    QString a[5]={"竞赛名称","级别","获奖名次","时间","学分值"};
    for(int i=0;i<5;i++)
    {
        headerItem=new QListWidgetItem;
        headerItem->setSizeHint(QSize(200, 60));
        headerItem->setText(a[i]);
        ui->listWidget->addItem(headerItem);
    }


    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));
}

//技能证书
void Dialog::on_radioButton_5_clicked()
{
    ui->listWidget->clear();

    //添加标题
    QListWidgetItem* headerItem;
    QString a[3]={"证书名称","获得时间","编号(有则填)"};
    for(int i=0;i<3;i++)
    {
        headerItem=new QListWidgetItem;
        headerItem->setText(a[i]);
        headerItem->setSizeHint(QSize(200, 60));
        ui->listWidget->addItem(headerItem);
    }


    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));
}

//创业实践和创新创业教育

void Dialog::on_radioButton_6_clicked()
{
    ui->listWidget->clear();

    //添加标题
    QListWidgetItem* headerItem;
    QString a[3]={"参加创业实践或创新创业教育名称","参加时间","是否有证书"};
    for(int i=0;i<3;i++)
    {
        headerItem=new QListWidgetItem;
        headerItem->setText(a[i]);
        headerItem->setSizeHint(QSize(200, 60));
        ui->listWidget->addItem(headerItem);
    }


    connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(textchange(QListWidgetItem*)));
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();
}
