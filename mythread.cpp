#include "mythread.h"

MyThread::MyThread(int id,QTcpSocket *socket,QTcpServer *server,QObject *parent) :
    QThread(parent)
{
     run(id,socket);
     exec();
}
void MyThread::run(int id,QTcpSocket *sock)
{
   int i =0;
   if (id ==1)
   {

       sock->write("1");
       sock->flush();
       sock->close();
       //sleep(1000);

   }
   if (id==2)
   {

        sock->write("2");
        sock->flush();
        sock->close();
        //sleep(1000);

   }


}
