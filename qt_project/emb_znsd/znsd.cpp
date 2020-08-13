#include "znsd.h"

znsd::znsd(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer())
{
    fd = serialOpen ("/dev/ttyUSB0", 57600);
    qDebug() << fd;
    connect(m_timer,&QTimer::timeout,[=](){
        QString recieved_ = UART_Qeury("$10;");
        QString display_ ;
    });
    m_timer->start(200);
}

QString znsd::number2Qstring(int numb)
{
    qDebug() << numb;
    return QString::number(numb);
}

void znsd::Status_Decode(QList<int> s)
{
    if(s.length() > 2)
    {
        status.power = 50;
        status.frequency = 100;
        status.pulsewidth = 20;
        status.ext_modulation = true;
        status.modulation_on = true;
        status_signal(status.power, status.frequency, status.pulsewidth, status.ext_modulation, status.modulation_on );
        enable_signal(true);
    }
    enable_signal(false);
}

QString znsd::UART_Qeury(QString command)
{
    QString result;
    std::string s = "";
    QList<int> charList;
    while(  serialDataAvail (fd) > 0)
    {
        char x = (char)serialGetchar(fd);
        charList.append(x);
        s.append( sizeof(char),  x);
    }
    qDebug() << charList;
    Status_Decode(charList);
    result = s.c_str();
    std::string cmd =  command.toUtf8().constData();
    cmd.append(sizeof(char), 0x0D );
    serialPuts(fd, cmd.c_str() );
    return  result;
}
