#ifndef POWERPROTECT_H
#define POWERPROTECT_H

#include <QObject>
#include <QTimer>
#include <wiringSerial.h>

class Powerprotect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString power_display READ power_display WRITE setPower_display NOTIFY power_displayChanged)

    QString m_power_display;

public:
    explicit Powerprotect(QObject *parent = nullptr);

QString power_display() const;

public slots:
void setPower_display(QString power_display);

signals:

void power_displayChanged(QString power_display);

private:
QString UART_Qeury(QString command);
QString convert_2_powerdisplay(double val);
bool is_number(QString val);
QTimer* m_timer;
int fd;
};

#endif // POWERPROTECT_H
