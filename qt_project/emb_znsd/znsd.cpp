#include "znsd.h"

znsd::znsd(QObject *parent) :
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
    connect(this, &znsd::command_signal,[=](QString cmd){
        uart_command = cmd;
    } );
}

QString znsd::number2Qstring(int numb)
{    
    return QString::number(numb);
}

bool znsd::get_update_delay()
{
    return disable_counter != 0 ;
}

QString znsd::get_alarmString(int alarm_code)
{
    QString result;
    switch (alarm_code) {
    case 0:        result = "NORMAL";        break;
    case 1:        result = "SEED_PD";        break;
    case 2:        result = "CALMAR_FAULT";        break;
    case 3:        result = "PD1";        break;
    case 4:        result = "PD2";        break;
    case 5:        result = "PD3";        break;
    case 6:        result = "PD4";        break;
    case 7:        result = "PD5";        break;
    case 8:        result = "PD6";        break;
    case 9:        result = "CURRENT_UPPER_LIMIT1";        break;
    case 10:        result = "CURRENT_UPPER_LIMIT2";        break;
    case 11:        result = "CURRENT_UPPER_LIMIT3";        break;
    case 12:        result = "CURRENT_UPPER_LIMIT4";        break;
    case 13:        result = "CURRENT_UPPER_LIMIT5";        break;
    case 14:        result = "CURRENT_UPPER_LIMIT6";        break;
    case 15:        result = "INTERLOCK";        break;
    case 16:        result = "LIMIT_SWITCH";        break;
    case 17:        result = "EMERGENCY_STOP_SWITCH";        break;
    case 18:        result = "CALMAR_SEED_FAULT";        break;
    default:
        break;
    }
    result.append("(");
    result.append(QString::number(alarm_code));
    result.append(")");
    return result ;
}

bool znsd::Status_Check(QList<int> s)
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

void znsd::Status_update(QList<int> s)
{
    if(Status_Check(s))
    {
        status.power = s[3];
        status.frequency = s[5]*256 + s[6];
        status.pulsewidth = s[7]*256 + s[8];

        int sta = s[2];
        status.modulation_on = (sta & 0x20) != 0;
        status.ext_modulation = (sta & 0x40) != 0;
        status.coded = (sta & 0x04 ) != 0;
        status.guide_laser = (sta & 0x10) != 0;
        status.key = (sta & 0x08) != 0;
        status.warningcode = s[4];

        status_signal(status.power, status.frequency, status.pulsewidth,
                      status.ext_modulation,
                      status.modulation_on,
                      status.key,
                      status.coded,
                      status.guide_laser,status.warningcode );
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
