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
#include <QStringBuilder>
#include "file_io.h"
#include "config.h"

typedef struct rust_status
{
    int laser_power;
    int laser_frequency;
    int scan_width;
    int scan_frequency;
    bool modulation_on;
}STATUS;

typedef struct keyboard_input
{
    int value;
    int max_value;
    int min_value;
    file_io::parameter title;
}MINIKEYBOARD;

class rust : public QObject
{
    Q_OBJECT

public:
    explicit rust(QObject *parent = nullptr);
    STATUS status;
    MINIKEYBOARD kb;
    file_io f_io;

public slots:    
    void save_recipe(int index);
    void load_recipe(int index);
    int get_status_power();
    int get_status_frequency();
    int get_status_rate();
    int get_status_range();
    QString get_quick_msg(int index);
    //keyboard**************************************************
    void insert_keyboard_value(int value);
    void clear_keyboard_value();
    void delete_keyboard_value();
    int get_kb_value();
    bool is_kb_in_range();
    QString get_kb_title();
    void kb_ok();
    void start_popup(int index);
    //**********************************************************

signals:
    void status_signal();
    void enable_signal(bool enb);
    void command_signal(QString cmd);
    void change_keyboard();

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
