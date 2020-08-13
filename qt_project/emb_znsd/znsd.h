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
    bool ext_modulation;
    bool modulation_on;
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
    void status_signal(int power, int frequency, int pulsewidth, bool ext, bool modulation);
    void enable_signal(bool enb);

private:
    QTimer* m_timer;
    int fd;

    void Status_Decode(QList<int> s);
    QString UART_Qeury(QString command);
};

#endif // ZNSD_H
