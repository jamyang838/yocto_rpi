#include "fileio.h"
#include <QTextStream>


FileIO::FileIO(QObject *parent) : QObject(parent)
{

}

void FileIO::filenameGen()
{
    QDateTime current =  QDateTime::currentDateTime();
    filename.clear();
    filename = QString::number( current.date().year() );
    filename+= "_";
    filename +=  QString::number( current.date().month() );
    filename += "_";
    filename +=  QString::number( current.date().day() );
    filename += "_";
    filename +=  QString::number( current.time().hour() );
    filename += "_";
    filename +=  QString::number( current.time().minute() );
    filename +="_";
    filename +=  QString::number( current.time().second() );
    filename += ".csv";
}

void FileIO::CreateFile()
{
    filenameGen();
    starttime = QDateTime::currentDateTime();
    QFile data(filename);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        out << "time(ms),power(W),limit(up),limit(low),relay\n";
    }
}

void FileIO::SaveFile(QDateTime time, double power, double uplimit, double lowlimit, bool relay)
{
    int ms = starttime.msecsTo(time);
    QFile data(filename);
    if (data.open(QFile::WriteOnly | QFile::Append)) {
        QTextStream out(&data);
        out << ms <<"," << power << "," << uplimit<< "," << lowlimit << "," << relay << "\n";}
}

QDateTime FileIO::get_starttime()
{
    return starttime;
}



