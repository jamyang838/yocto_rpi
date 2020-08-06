#include "fileio.h"
#include <QDebug>



FileIO::FileIO(QObject *parent) : QObject(parent)
{    
    /* In windows, this will init the winsock stuff */
     curl_global_init(CURL_GLOBAL_ALL);

     //curl_global_cleanup();
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

void FileIO::CreateCloud()
{
    CURL *curl;
    CURLcode  res;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://home.m200.nctu.me/api_protect/api/TablePowerHeaders");
        curl_easy_setopt(curl, CURLOPT_POST, 1);
         struct curl_slist* headers = NULL;
         std::list<std::string> listRequestHeader;
         listRequestHeader.push_back("Content-Type:application/json;charset=UTF-8");         
         std::list<std::string>::iterator iter, iterEnd;
         iter = listRequestHeader.begin();
         iterEnd = listRequestHeader.end();
         headers = curl_slist_append(headers, iter->c_str());
         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);//設定http請求頭資訊
         curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
         curl_easy_setopt(curl, CURLOPT_POSTFIELDS,  convert_json::convert_header().toUtf8().constData());
         res =  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_header_data);
         curl_easy_perform(curl);
         qDebug() << curl_easy_strerror(res);
         curl_easy_cleanup(curl);
    }
}

void FileIO::SaveFile(QDateTime time, double power, double uplimit, double lowlimit, bool relay)
{
    int ms = starttime.msecsTo(time);
    QFile data(filename);
    if (data.open(QFile::WriteOnly | QFile::Append)) {
        QTextStream out(&data);
        out << ms <<"," << power << "," << uplimit<< "," << lowlimit << "," << relay << "\n";}
    SaveCloud(ms, power);
}

void FileIO::SaveCloud(int time_ms, double power)
{
    if(header_id != -1)
    {
        CURL *curl;
        CURLcode  res;
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "http://home.m200.nctu.me/api_protect/api/TableDetail/");
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
             struct curl_slist* headers = NULL;
             std::list<std::string> listRequestHeader;
             listRequestHeader.push_back("Content-Type:application/json;charset=UTF-8");
             std::list<std::string>::iterator iter, iterEnd;
             iter = listRequestHeader.begin();
             iterEnd = listRequestHeader.end();
             headers = curl_slist_append(headers, iter->c_str());
             curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);//設定http請求頭資訊
             curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
             const char* s = convert_json::convert_detail(header_id, time_ms, power).toUtf8().constData();
             strcpy(tramsmission, s);
             qDebug() << s;
             curl_easy_setopt(curl, CURLOPT_POSTFIELDS, tramsmission );
             res =  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_detail_data);
             curl_easy_perform(curl);
             qDebug() << curl_easy_strerror(res);
             curl_easy_cleanup(curl);
        }
    }
}

size_t FileIO::write_header_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    char* xxx = (char*)buffer;
    qDebug() << xxx;
    QString str = QString(xxx);
    QRegExp re("\"id\":(\\d+)");
    qDebug() << str.indexOf(re);    
    qDebug() << "900772";
    header_id = re.cap(1).toInt();
    //qDebug() << header_id;
    return size;
}

size_t FileIO::write_detail_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
    //char* xxx = (char*)buffer;
    qDebug() <<(char*)buffer ;
    QString str = QString((char*)buffer);
    QRegExp re("\"id\":(\\d+)");
    qDebug() << re.cap(1).toDouble() ;
    return size;
}


QDateTime FileIO::get_starttime()
{
    return starttime;
}



