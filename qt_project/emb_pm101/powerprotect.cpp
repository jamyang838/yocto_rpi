#include "powerprotect.h"

Powerprotect::Powerprotect(QObject *parent) : QObject(parent),    
    m_timer(new QTimer(this)),
    m_uplimit(0),m_lowlimit(0)
{
    //Test******************************************************

    //Curl******************************************************

    //Init*******************************************************
    is_upperlimit = false;
    is_lowerlimit = false;
    is_save = false;
    save_timer_period = 1000;
    //Pin*******************************************************
    wiringPiSetup();
    pinMode(PIN_RELAY ,OUTPUT);    
    //**********************************************************
    //fd = serialOpen ("/dev/serial0", 115200);
    fd = serialOpen ("/dev/ttyUSB0", 115200);
    connect(m_timer,&QTimer::timeout,[=](){
        double power_value ;
        //Query****************************************
        QString recieved_ = Powerprotect::UART_Qeury("MEAS:POW?");
        QString display_ ;
        if(is_number(recieved_))
        {
            power_value = recieved_.toDouble();
            display_ = Powerprotect::convert_2_powerdisplay( power_value );

            if(
                    ( (power_value > uplimit()) && is_upperlimit )||
                    ( (power_value < lowlimit()) && is_lowerlimit )
                    )
            {
                shutdown_relay();
            }
        }
        else
        {
            display_ = "--";
        }
        setPower_display(display_);
        //Save*****************************************
        if(is_save)
        {
            double _time1 = last_datetime.msecsTo(QDateTime::currentDateTime());
            if( _time1 >= save_timer_period )
            {
                last_datetime = QDateTime::currentDateTime();
                file.SaveFile(
                            last_datetime,
                            power_value,
                            is_upperlimit? uplimit() : -1,
                            is_lowerlimit? lowlimit() : -1,
                            digitalRead(PIN_RELAY) );
            }
        }
    });

    m_timer->start(200);
}

void Powerprotect::set_limit(QString str)
{
    bool validate;
    double _val;
    _val = str.toDouble(&validate);
    if(validate)
    {
        if(Powerprotect::is_set_upperlimit)
        {
            setUplimit(_val);
        }
        else
        {
            setLowlimit(_val);
        }
    }

}

QString Powerprotect::power_display() const
{
    return m_power_display;
}

QString Powerprotect::limit_display() const
{
    return m_limit_display;
}

double Powerprotect::uplimit() const
{
    return m_uplimit;
}

double Powerprotect::lowlimit() const
{
    return m_lowlimit;
}

void Powerprotect::set_is_set_upperlimit(bool val)
{
    is_set_upperlimit = val;
}

void Powerprotect::switch_upperlimit(bool val)
{
    is_upperlimit = val;
}

void Powerprotect::switch_lowerlimit(bool val)
{
    is_lowerlimit = val;
}

void Powerprotect::switch_savefile(bool val)
{
    if(val)
    {
        file.CreateFile();
        file.CreateCloud();
    }
    last_datetime = file.get_starttime();
    is_save = val;
}

void Powerprotect::setPower_display(QString power_display)
{
    if (m_power_display == power_display)
        return;

    m_power_display = power_display;
    emit power_displayChanged(m_power_display);
}

void Powerprotect::switch1_slot(bool val)
{
    int _value;
    if(val)
        _value = 1;
    else
        _value = 0;
    digitalWrite(PIN_RELAY,_value);
}

void Powerprotect::input_number(QString str)
{
    setLimit_display( m_limit_display + str);
}

void Powerprotect::input_click(QString str)
{
    if(str.toLower() == "ok")
    {
        Powerprotect::set_limit( limit_display() );
    }
    else if(str.toLower() ==  "cancel")
    {

    }
}

void Powerprotect::setLimit_display(QString limit_display)
{
    if (m_limit_display == limit_display)
        return;

    m_limit_display = limit_display;
    emit limit_displayChanged(m_limit_display);
}

void Powerprotect::setUplimit(double uplimit)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_uplimit, uplimit))
        return;

    m_uplimit = uplimit;
    emit uplimitChanged(m_uplimit);
}

void Powerprotect::setLowlimit(double lowlimit)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_lowlimit, lowlimit))
        return;

    m_lowlimit = lowlimit;
    emit lowlimitChanged(m_lowlimit);
}

QString Powerprotect::UART_Qeury(QString command)
{
    QString result;
    //return "0.0123456789";

    /*
    if ((fd = serialOpen ("/dev/serial0", 115200)) < 0)
      {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
      }
    else
    {
    */
    //read
    std::string s = "";
    while(  serialDataAvail (fd) > 0)
    {
        s.append( sizeof(char), (char)serialGetchar(fd) );
    }
    result = s.c_str();
    //serialPuts(fd, s.c_str());

    std::string cmd =  command.toUtf8().constData();
    cmd.append(sizeof(char), 0x0A );
    serialPuts(fd, cmd.c_str() );

    return  result;
}

QString Powerprotect::convert_2_powerdisplay(double val)
{
    QString result = "";
    QString unit = "";
    double convert_number;
    if(val < 1E-6)
    {
        convert_number = val * 1E9;
        unit = "nW";
    }
    else if(val < 1E-3)
    {
        convert_number = val * 1E6;
        unit = "uW";
    }
    else if(val < 1)
    {
        convert_number = val * 1E3;
        unit = "mW";
    }
    else{
        convert_number = val;
        unit = "W";
    }
    result = QString::number(convert_number, 'f',2);
    return result + unit;
}

bool Powerprotect::is_number(QString val)
{

    QRegExp re("\\d+\\.*\\d*\\e*\\-*\\d*\n");
    /*
    if (re.exactMatch(somestr))
       qDebug() << "all digits";
       */
    bool result = re.exactMatch(val);
    return result;
    //return true;
}
