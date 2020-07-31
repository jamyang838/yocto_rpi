#ifndef FILEIO_H
#define FILEIO_H

#include <QObject>
#include <QFile>
#include <QDateTime>

class FileIO : public QObject
{
    Q_OBJECT
public:
    explicit FileIO(QObject *parent = nullptr);

    void CreateFile( void );
    void SaveFile( QDateTime time, double power, double uplimit, double lowlimit, bool relay);
    QDateTime get_starttime();

public slots:

signals:

private:
    void filenameGen( void );
    QDateTime starttime;
    QString filename;
};

#endif // FILEIO_H
