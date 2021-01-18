#include "rust.h"

rust::rust(QObject *parent) :
    QObject(parent),
    m_timer(new QTimer()),
    uart_command(""),
    disable_counter(0)
{
    fd = serialOpen ("/dev/ttyUSB0", 57600);    
    connect(m_timer,&QTimer::timeout,[=](){
        QString recieved_;
        if(disable_counter != 0)
        {
            uart_command = "";
        }
        if(uart_command!="")
        {
            disable_counter ++;
            recieved_ = UART_Qeury(uart_command);
        }
        else
        {
            recieved_ = UART_Qeury("$10;");
        }
    });
    m_timer->start(50);
    //***********************************************
    status.laser_power = 0;
    status.laser_frequency = 0;
    status.scan_width = 0;
    status.scan_frequency = 0;
    //***********************************************
    connect(this, &rust::command_signal,[=](QString cmd){
        uart_command = cmd;
    } );
}

void rust::save_recipe(int index)
{

    qDebug() << f_io.jsonArray ;
    qDebug() << "=======================================\n";
    status.laser_power = 5; //TODO

    f_io.update_recipe(index,status.laser_power, status.laser_frequency, status.scan_frequency, status.scan_width);
    qDebug() << f_io.jsonArray ;
    f_io.save_recipes();
}

void rust::load_recipe(int index)
{
    int _power = f_io.get_value(index,f_io.parameter::POWER );
    int _frequency = f_io.get_value(index,f_io.parameter::FREQUENCY );
    int _rate = f_io.get_value(index,f_io.parameter::RATE );
    int _range = f_io.get_value(index,f_io.parameter::RANGE );
    qDebug() << "ready\n";
    rust::status_signal(); //TODO
    uart_command = ""; //TODO
}

int rust::get_status_power()
{
    return  status.laser_power;
}

int rust::get_status_frequency()
{
    return status.laser_frequency;
}

int rust::get_status_rate()
{
    return status.scan_frequency;
}

int rust::get_status_range()
{
    return status.scan_frequency;
}
/*
QString rust::number2Qstring(int numb)
{
    return QString::number(numb);
}
bool rust::get_update_delay()
{
    return disable_counter != 0 ;
}
*/
bool rust::Status_Check(QList<int> s)
{
    int first_index = s.indexOf(0xFF);
    int last_index = s.lastIndexOf(13);

    //****************************************************************
    if( (last_index - first_index) != 12 )
    {
        return false;
    }
    //****************************************************************
    //QList<int> sub = s.mid(first_index, last_index - first_index  );
    /*
                var obj = data.Skip(first_index).Take(last_index - first_index).ToList();
                int checksum = 0;
                for(int i=0; i< obj.Count - 1; i++ )
                {
                    checksum += obj[i];
                }
                checksum = checksum % 256;
                if (
                    obj.Count == 12
                    && (obj[0] == 0xff)
                    && (obj[1] == 0xff)
                    && (obj[9] == 0xfe)
                    && (obj[10] == 0xff
                    && obj[11] == checksum)
                    )
                    return true;
                else
                    return false;
                */

    return true;
}

void rust::Status_update(QList<int> s)
{
    if(Status_Check(s))
    {
        status.laser_power = s[3];
        status.laser_frequency = s[4];
        status.scan_width = s[8];
        status.scan_frequency = s[6];

        int sta = s[2];

        status.modulation_on = (sta & 0x20) != 0;

        status_signal();
        enable_signal(true);
        disable_counter = 0;
    }
    else if(s.length() > 0 && uart_command!="")
    {
        uart_command = "";
    }
    else
    {
        if(disable_counter > 5 )
        {
            enable_signal(false);            
        }
        else
        {
            disable_counter++;
        }
    }    
}

QString rust::UART_Qeury(QString command)
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
    //qDebug() << charList;
    Status_update(charList);
    result = s.c_str();
    std::string cmd =  command.toUtf8().constData();
    cmd.append(sizeof(char), 'a' );
    cmd.append(sizeof(char), 0x0D );
    serialPuts(fd, cmd.c_str() );
    uart_command = "";
    return  result;
}

