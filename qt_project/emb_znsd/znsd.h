#ifndef ZNSD_H
#define ZNSD_H

#include <QObject>
#include <QString>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <stdbool.h>

typedef struct znsd_status
{
    int power;
    int frequency;
    int pulsewidth;
    int warningcode;
    bool ext_modulation;
    bool modulation_on;
    bool key;
    bool guide_laser;
    bool coded;
}STATUS;

class znsd : public QObject
{
    Q_OBJECT

public:
    explicit znsd(QObject *parent = nullptr);            
    STATUS status;

public slots:
QString number2Qstring(int numb);

signals:
    void status_signal(int power, int frequency, int pulsewidth,
                       bool ext, bool modulation, bool key,
                       bool coded,bool guide_laser, int warning);
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

#endif // ZNSD_H
