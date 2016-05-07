#include "widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* layout = new QVBoxLayout;

    socket = new QUdpSocket;
    edit = new QLineEdit;
    button = new QPushButton;
    layout->addWidget(button);
    layout->addWidget(edit);
    this->setLayout(layout);
    socket->bind(QHostAddress::Any,12000);
    connect(socket,SIGNAL(readyRead()),this,SLOT(displayData()));
    connect(button,SIGNAL(clicked(bool)),this,SLOT(sendStuff()));
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

void Widget::sendStuff()
{
    QByteArray d("PLEASE WORK");
    int sent = socket->writeDatagram(d,QHostAddress::LocalHost,13000);
    qDebug() << sent;
}
