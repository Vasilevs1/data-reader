#include "widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{

    socket = new QUdpSocket;
    edit = new QLineEdit(this);
    socket->bind(QHostAddress::LocalHost,12000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(displayData()));
}

Widget::~Widget()
{

}

void Widget::displayData()
{
    while(socket->hasPendingDatagrams())
    {
        QByteArray data;
        data.resize(socket->pendingDatagramSize());
        QHostAddress addr;
        quint16 senderPort;
        socket->readDatagram(data.data(),data.size(),&addr,&senderPort);
        qDebug()<< data;
        QDataStream stream(&data,QIODevice::ReadOnly);
        int x,y;
        stream>>x>>y;
        edit->setText(QString::number(x)+QString::number(y));
    }

}
