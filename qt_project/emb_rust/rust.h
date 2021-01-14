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
    bool modulation_on;
}STATUS;

class rust : public QObject
{
    Q_OBJECT

public:
    explicit rust(QObject *parent = nullptr);
    STATUS status;

public slots:
    QString number2Qstring(int numb);
    bool get_update_delay();

signals:
    void status_signal(int power, int frequency, int scan_width, int scan_frequency, bool modulation_on);
    void enable_signal(bool enb);
    void command_signal(QString cmd);

private:
    QTimer* m_timer;
    QString uart_command;
    int disable_counter;
    int fd;
    bool Status_Check(QList<int> s);
    void Status_update(QList<int> s);
    QString UART_Qeury(QString uart_command);


};

#endif // RUST_H
