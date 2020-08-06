#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QRegExp>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <curl/curl.h>
#include "convert_json.h"

class FileIO : public QObject
{
    Q_OBJECT
public:
    explicit FileIO(QObject *parent = nullptr);
    void CreateFile( void );
    void CreateCloud( void );
    void SaveCloud(int time_ms, double power);
    void SaveFile( QDateTime time, double power, double uplimit, double lowlimit, bool relay);    
    QDateTime get_starttime();
    static int header_id;

public slots:

signals:

private:
    char tramsmission[250];
    void filenameGen( void );
    QDateTime starttime;
    QString filename;
    static size_t write_header_data(void *buffer, size_t size, size_t nmemb, void *userp);
    static size_t write_detail_data(void *buffer, size_t size, size_t nmemb, void *userp);

};

#endif // FILEIO_H
