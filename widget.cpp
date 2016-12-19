#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>
#include <QByteArray>
#include <QIODevice>
#include <QTimer>
#include <QPixmap>
#include <QBuffer>
#include <QFile>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket = new QTcpSocket;
    server = new QTcpServer;
    data2 = new QByteArray;
    QTimer *timer =new QTimer(this);
    timer->setInterval(1000);
    connect(server,SIGNAL(newConnection()),this,SLOT(onsucconnection()));
    connect(timer,SIGNAL(timeout()),this,SLOT(ontimer()));
    connect(server,SIGNAL(newConnection()),timer,SLOT(start()));
    server->listen(QHostAddress::Any,6666);






}

Widget::~Widget()
{
    delete ui;
    delete server;
    delete socket;
}
void Widget::onsucconnection()
{
    ui->label->setText("connected");
     socket = server->nextPendingConnection();//已连接
}

void Widget::on_pushButton_clicked()
{
    //发送A
   // socket->setSocketDescriptor(1);
    //threadA->start();
   // socket->write("1111");
    //ID =1;

   MyThread *threadB =new MyThread(2,socket,server,this);
   if (threadA->isRunning())
   {
       threadA->deleteLater();
   }
   threadB->start();
   connect(threadB,SIGNAL(finished()),threadB,SLOT(deleteLater()));
}

void Widget::on_pushButton_2_clicked()
{
    //发送B
    //socket->setSocketDescriptor(2);
    //socket = server->nextPendingConnection();//已连接
   // QByteArray data2;
   /* socket = server->nextPendingConnection();//已连接
    data2->append("2222");

    //while(ID!=1)

     if(socket->write("2222"))
     {

        for(int i = 1;i<10;i++)
        {
            //socket->waitForBytesWritten(1);
            socket->write("2222\n");
            socket->flush();
        }

     }else
        ui->label->setText("error");*/
    MyThread *threadA =new MyThread(1,socket,server,this);
    connect(threadA,SIGNAL(finished()),threadA,SLOT(deleteLater()));
    threadA->start();
    if (threadA->isRunning())
    {
        ui->label->setText("error");
    }
}

void Widget::on_pushButton_3_clicked()
{
    //发送C
    QByteArray byteArr;
   // QImage image;
   // image.load("C:\Users\Administrator\Desktop\QQ.jpg","jpg");
   // QBuffer buffer(,this);
   // byteArr.append(buffer.data());
    QFile f("C:/Users/Administrator/Desktop/QQ.jpg");
    f.open(QIODevice::ReadOnly);
    byteArr = f.readAll();
    f.close();
    int n = socket->write(byteArr);




}

void Widget::on_pushButton_4_clicked()
{
    //停止
    exit(0);
}
void Widget::ontimer()
{
    //socket->setSocketDescriptor(2);
    //socket = server->nextPendingConnection();//已连接
    //socket->waitForBytesWritten(50);
    //socket->write("2222\n");
    //socket->flush();
    //socket->write(data2,sizeof(data2));

}
