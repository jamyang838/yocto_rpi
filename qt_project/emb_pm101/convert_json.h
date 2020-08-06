#ifndef CONVERT_JSON_H
#define CONVERT_JSON_H

#include <QString>
#include <QtNetwork>
#include <QDateTime>
#include <QDebug>

class convert_json
{
public:
    convert_json();
    static QString get_wlan0_mac();
    static QString convert_header();
    static QString convert_detail(int head_id,int ms, double power);
};

#endif // CONVERT_JSON_H
