#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include "mythread.h"
#include <QTcpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget( QWidget *parent = 0);
    ~Widget();
    QByteArray *data2;

private:
    Ui::Widget *ui;
    QTcpServer *server;
    QTcpSocket *socket;
    int ID;
    MyThread *threadA;

private slots:
    void onsucconnection();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void ontimer();
};

#endif // WIDGET_H
