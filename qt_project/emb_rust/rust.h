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
#include "file_io.h"

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
    file_io f_io;

public slots:
    //QString number2Qstring(int numb);
    //bool get_update_delay();
    void save_recipe(int index);
    void load_recipe(int index);
    int get_status_power();
    int get_status_frequency();
    int get_status_rate();
    int get_status_range();

signals:
    void status_signal();
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
