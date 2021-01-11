#ifndef POWERPROTECT_H
#define POWERPROTECT_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QRegExp>
#include <QTimer>
#include <QDebug>
#include <string.h>
#include <ctime>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <curl/curl.h>
#include "fileio.h"

#define PIN_RELAY   25

class Powerprotect : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString power_display READ power_display WRITE setPower_display NOTIFY power_displayChanged)
    Q_PROPERTY(QString limit_display READ limit_display WRITE setLimit_display NOTIFY limit_displayChanged)
    Q_PROPERTY(double uplimit READ uplimit WRITE setUplimit NOTIFY uplimitChanged)
    Q_PROPERTY(double lowlimit READ lowlimit WRITE setLowlimit NOTIFY lowlimitChanged)        

public:    
    explicit Powerprotect(QObject *parent = nullptr);
    void set_limit(QString str);
    void get_lowerlimit(QString str);
    QString power_display() const;
    QString limit_display() const;
    double uplimit() const;
    double lowlimit() const;
    bool is_set_upperlimit;    

public slots:
    void setPower_display(QString power_display);
    void setLimit_display(QString limit_display);
    void setUplimit(double uplimit);
    void setLowlimit(double lowlimit);
    void switch1_slot(bool val);
    void input_number(QString str);
    void input_click(QString str);
    void set_is_set_upperlimit(bool val);
    void switch_upperlimit(bool val);
    void switch_lowerlimit(bool val);
    void switch_savefile(bool val);
    QString get_rpi_desc( void );
    void enter_advanced_mode(QString str);

signals:
    void power_displayChanged(QString power_display);
    void limit_displayChanged(QString limit_display);
    void uplimitChanged(double uplimit);
    void lowlimitChanged(double lowlimit);
    void update_limitswitch(void);
    void save_file(void);
    void shutdown_relay( void );
    void initial_signal(void);

private:
    FileIO file;
    int save_timer_period;
    QDateTime last_datetime;
    QString UART_Qeury(QString command);
    QString convert_2_powerdisplay(double val);
    bool is_number(QString val);
    QTimer* m_timer;
    int fd;
    QString m_limit_display;
    double m_uplimit;
    double m_lowlimit;
    QString m_power_display;
    bool is_upperlimit;
    bool is_lowerlimit;
    bool is_save;
    QString mac_num;
};

#endif // POWERPROTECT_H
