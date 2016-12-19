#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int id,QTcpSocket *socket,QTcpServer *server,QObject *parent = 0);
    void run(int id,QTcpSocket *sock);

signals:

public slots:
public:
    QTcpSocket *socket;
    QTcpServer *server;
    int id;


};

#endif // MYTHREAD_H
