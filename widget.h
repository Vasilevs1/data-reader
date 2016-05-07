#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QLineEdit>
#include <QPushButton>
class Widget : public QWidget
{
    Q_OBJECT
    QUdpSocket* socket;
    QLineEdit* edit;
    QPushButton* button;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void displayData();
    void sendStuff();

};

#endif // WIDGET_H
