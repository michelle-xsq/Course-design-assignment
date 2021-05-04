/*
 * 导员审核成果
 * 通过保存到对应文件 未通过数据删除
 * 2021-03-11-xsq
 */
#include "to_examine.h"
#include "ui_to_examine.h"
#include "QTableWidget"
#include "QTableWidgetItem"
#include "QString"
#include "QStringList"
#include "QFile"
#include "QPropertyAnimation"

To_examine::To_examine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::To_examine)
{

    ui->setupUi(this);
    //设置界面标题
    setWindowTitle(QString("大学生课外科技活动成果管理系统"));
    //设置界面图标
    setWindowIcon(QIcon("E:\\Qt\\hello\\datastructure\\wust.jpg"));
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //自适应列宽

    //设置界面背景
    setWindowFlags(Qt::WindowCloseButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    QPixmap pixmap("E:\\Qt\\hello\\datastructure\\background.jpg");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    QPalette palette2=this->palette();
    palette2.setBrush(QPalette::WindowText,Qt::white);
    this->setPalette(palette2);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(sort(int)));

    //进入动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

To_examine::~To_examine()
{
    delete ui;
}

//排序
void To_examine::sort(int column)
{
    static bool f = true;
    ui->tableWidget->sortByColumn(column, f ? Qt::AscendingOrder : Qt::DescendingOrder);
    f = !f;
}

//关闭界面
void To_examine::on_pushButton_clicked()
{

    this->close();
}

//清空目前列表
void To_examine::qing()
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
    ui->label_3->setText("");
}

//具体每行数据显示
void To_examine::open_txt(QString d)
{
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
            QFont font;
            font.setBold(true);//设置为粗体
            font.setPointSize(11);//字体大小
            item->setFont(font);
            item->setTextAlignment(Qt::AlignHCenter);
            ui->tableWidget->setItem(row,i,item);
        }
        item=new QTableWidgetItem;
        item->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(row,ui->tableWidget->columnCount()-1,item);
    }
    f.close();

}



//提交 审核过数据
void To_examine::on_pushButton_14_clicked()
{
    if(ui->tableWidget->rowCount()==0)return;
    QTableWidgetItem *item=new QTableWidgetItem(ui->tableWidget->item(0,0)->text());
    //提取第一个字节 分列别

    if(item!=NULL){
    //提取出item text
        QString one_text=ui->tableWidget->item(0,0)->text(),d1,d2;
        if(one_text=="国家级省级科技成果奖"||one_text=="论文"||one_text=="在报刊、杂志上发表作品"||one_text=="其它")
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研成果.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
        }
        else if(one_text.contains("科研训练"))
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\科研训练.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研训练.txt";

        }else if(one_text.contains("获得专利")||one_text.contains("软件著作权")||one_text.contains("其他"))
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\知识产权.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
        }else if(one_text.contains("学科与科技竞赛"))
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\学科与科技竞赛.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核学科与科技竞赛.txt";
        }else if(one_text.contains("技能证书"))
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\技能证书.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核技能证书.txt";
        }else if(one_text.contains("创业实践和创新创业教育"))
        {
            d2="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\创业实践和创新创业教育.txt";
            d1="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核创业实践和创新创业教育.txt";
        }
        QFile f1(d1);
        f1.open(QIODevice::ReadOnly | QIODevice::Text);
        QFile f2(d2);
        f2.open(QIODevice::Append | QIODevice::Text);
        int row_count=ui->tableWidget->rowCount(),c_count=ui->tableWidget->columnCount();
        for(int i=0;i<row_count;i++)
        {
            item=ui->tableWidget->item(i,c_count-1);
            QByteArray line=f1.readLine();
            QString s(line);
            if(item->checkState()==Qt::Checked)
            {
                f2.write(s.toUtf8());
            }
        }

        f1.close();
        f2.close();
        //清空未审核txt文件
        QFile shan(d1);
        shan.open(QIODevice::WriteOnly|QIODevice::Truncate);
        shan.close();
        ui->label_3->setText("保存成功");

    }

    //清空列表
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);
}

//科研成果数据抬头显示
void To_examine::on_pushButton_11_clicked()
{
    //清空目前table
    qing();

    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"成果名称"<<"备注（可写编号）"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研成果.txt";
    open_txt(d);
}

//科研训练
void To_examine::on_pushButton_8_clicked()
{
    //清空目前table
    qing();
    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"参加训练名称"<<"时间"<<"备注"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核科研训练.txt";
    open_txt(d);
}

//技能证书
void To_examine::on_pushButton_12_clicked()
{
    //清空目前table
    qing();
    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"证书名称"<<"获得时间"<<"编号(有则填)"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核技能证书.txt";
    open_txt(d);
}

//知识产权
void To_examine::on_pushButton_7_clicked()
{
    //清空目前table
    qing();
    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"成果名称"<<"备注（可写编号）"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核知识产权.txt";
    open_txt(d);
}

//学科与科技竞赛
void To_examine::on_pushButton_9_clicked()
{
    //清空目前table
    qing();
    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"竞赛名称"<<"级别"<<"获奖名次"<<"时间"<<"学分值"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核学科与科技竞赛.txt";
    open_txt(d);
}

//创业实践和创新创业教育

void To_examine::on_pushButton_13_clicked()
{
    //清空目前table
    qing();
    QTableWidgetItem *item;
    //设置表头
    QStringList str;
    str<<"类别"<<"姓名"<<"学号"<<"电话"<<"参加创业实践或创新创业教育名称"<<"参加时间"<<"是否有证书"<<"是否通过";
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
    QString d="E:\\Qt\\hello\\datastructure\\大学生课外科技活动成果\\未审核创业实践和创新创业教育.txt";
    open_txt(d);
}

//关界面
void To_examine::on_pushButton_2_clicked()
{
    this->close();
}
