#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QRegExp>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <curl/curl.h>

class FileIO : public QObject
{
    Q_OBJECT
public:
    explicit FileIO(QObject *parent = nullptr);

    void CreateFile( void );
    void CreateCloud( void );
    void SaveFile( QDateTime time, double power, double uplimit, double lowlimit, bool relay);    
    QDateTime get_starttime();

public slots:

signals:

private:
    int header_id;
    void filenameGen( void );
    QDateTime starttime;
    QString filename;
    static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);
};

#endif // FILEIO_H
