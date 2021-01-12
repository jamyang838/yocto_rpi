#ifndef RUST_H
#define RUST_H

#include <QObject>
#include <QString>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <stdbool.h>

typedef struct rust_status
{
    int laser_power;
    int laser_frequency;
    int scan_width;
    int scan_frequency;
}STATUS;

class rust : public QObject
{
    Q_OBJECT
public:
    explicit rust(QObject *parent = nullptr);
    STATUS status;
private:
    QTimer* m_timer;
    QString uart_command;
    int disable_counter;
    int fd;
    bool Status_Check(QList<int> s);
    void Status_update(QList<int> s);
    QString UART_Qeury(QString uart_command);
signals:

};

#endif // RUST_H
