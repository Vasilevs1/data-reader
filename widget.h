#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>
#include <QLineEdit>
class Widget : public QWidget
{
    Q_OBJECT
    QUdpSocket* socket;
    QLineEdit* edit;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void displayData();

};

#endif // WIDGET_H
