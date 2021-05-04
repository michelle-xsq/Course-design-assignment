/*
 *学生通过名字查询自己提交的成果
 * 以tablewidget展示成果
 * 通过显示绿色 正在审核显示红色
 * 2021-03-11-徐思群
 */
#include "look.h"
#include "ui_look.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QPropertyAnimation"

Look::Look(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Look)
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

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //自适应列宽
    //ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch); //自适应行高

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(sort(int)));

    //进入动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

Look::~Look()
{
    delete ui;
}

//排序
void Look::sort(int column)
{
    static bool f = true;
    ui->tableWidget->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

//关闭界面
void Look::on_pushButton_clicked()
{
    this->close();
}

//查询txt文件

void Look::search_txt(QString d)
{
    //读入文件中科研成果显示到table中
    QFile f(d);
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    while(!f.atEnd())
    {
        //将数据提取出来
        QByteArray line=f.readLine();
        QString s(line);if(s=="\n")continue;
        QStringList list = s.split(" ");


        int row=ui->tableWidget->rowCount();

        ui->tableWidget->insertRow(row);
        QTableWidgetItem *item;
        for(int i=0;i<list.count();i++)
        {
            item=new QTableWidgetItem(list.at(i));
            item->setTextAlignment(Qt::AlignCenter);
            QFont font;
            //font.setBold(true);//设置为粗体
            font.setPointSize(11);//字体大小
            item->setFont(font);

            ui->tableWidget->setItem(row,i,item);
        }

    }
    f.close();

}

//科研成果
void Look::on_pushButton_10_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"成果名称"<<"备注（可写编号）";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);

        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研成果.txt";
    search_txt(d);

}

//科研训练
void Look::on_pushButton_3_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"参加训练名称"<<"时间"<<"备注";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研训练.txt");
    search_txt(d);

}

//技能证书
void Look::on_pushButton_5_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"证书名称"<<"获得时间"<<"编号(有则填)";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\技能证书.txt");
    search_txt(d);

}

//知识产权
void Look::on_pushButton_2_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"成果名称"<<"备注（可写编号）";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\知识产权.txt");
    search_txt(d);
}

//学科与科技竞赛
void Look::on_pushButton_4_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"竞赛名称"<<"级别"<<"获奖名次"<<"时间"<<"学分值";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\学科与科技竞赛.txt");
    search_txt(d);
}

//创业实践和创新创业教育
void Look::on_pushButton_6_clicked()
{
    //清空目前table
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"参加创业实践或创新创业教育名称"<<"参加时间"<<"是否有证书";
    //设置tablewidget列数
    ui->tableWidget->setColumnCount(str.count());
    //将列名称输入 table
    for(int i=0;i<ui->tableWidget->columnCount();i++)
    {
        item=new QTableWidgetItem(str.at(i));
        QFont font;
        font.setBold(true);//设置为粗体
        font.setPointSize(11);//字体大小
        item->setFont(font);
        ui->tableWidget->setHorizontalHeaderItem(i,item);
    }
    QString d("E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\创业实践和创新创业教育.txt");
    search_txt(d);
}
