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
    f_io.update_recipe(index,status.laser_power, status.laser_frequency, status.scan_frequency, status.scan_width);    
    f_io.save_recipes();
}

void rust::load_recipe(int index)
{
    int _power = f_io.get_value(index,f_io.parameter::POWER );
    int _frequency = f_io.get_value(index,f_io.parameter::FREQUENCY );
    int _rate = f_io.get_value(index,f_io.parameter::RATE );
    int _range = f_io.get_value(index,f_io.parameter::RANGE );
    QString send_msg = QString("$34;"
                               + QString().number(_power)+ ","
                               + QString().number(_frequency)+ ","
                               + QString().number(_rate)+ ","
                               + QString().number(_range) );
    uart_command = send_msg;
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
    return status.scan_width;
}

QString rust::get_quick_msg(int index)
{    
    int _power = f_io.get_value(index,f_io.parameter::POWER );
    int _frequency = f_io.get_value(index,f_io.parameter::FREQUENCY );
    int _rate = f_io.get_value(index,f_io.parameter::RATE );
    int _range = f_io.get_value(index,f_io.parameter::RANGE );
    return QString(
                "power: " + QString().number(_power)
                +"\nfrequency:"+ QString().number(_frequency)
                +"\nscan rate:"+ QString().number(_rate)
                +"\nscan range:"+ QString().number(_range) );
}

void rust::insert_keyboard_value(int value)
{
    kb.value = kb.value * 10 + value;
}

void rust::clear_keyboard_value()
{
    kb.value = 0;
}

void rust::delete_keyboard_value()
{
    kb.value = kb.value / 10;
}

int rust::get_kb_value()
{
    return kb.value;
}

bool rust::is_kb_in_range()
{
    return (kb.value >= kb.min_value) && (kb.value <= kb.max_value);
}

QString rust::get_kb_title()
{
    QString result("[");
    switch (kb.title) {
    case file_io::parameter::POWER:
        result.append("POWER");
        break;
    case file_io::parameter::FREQUENCY:
        result.append("FREQUENCY");
        break;
    case file_io::parameter::RATE:
        result.append("SCAN RATE");
        break;
    case file_io::parameter::RANGE:
        result.append("SCAN RANGE");
        break;
    default:
        break;
    }
    result.append("]");
    return result;
}

void rust::kb_ok()
{

    int _power = status.laser_power;
    int _frequency = status.laser_frequency;
    int _rate = status.scan_frequency;
    int _range = status.scan_width;

    switch (kb.title) {
    case file_io::parameter::POWER:
        _power = kb.value;
        break;
    case file_io::parameter::FREQUENCY:
        _frequency = kb.value;
        break;
    case file_io::parameter::RATE:
        _rate = kb.value;
        break;
    case file_io::parameter::RANGE:
        _range = kb.value;
        break;
    default:
        break;
    }

    QString send_msg = QString("$34;"
                               + QString().number(_power)+ ","
                               + QString().number(_frequency)+ ","
                               + QString().number(_rate)+ ","
                               + QString().number(_range) );
    uart_command = send_msg;
}

void rust::start_popup(int index)
{
    switch (index) {
    case 0:
        kb.title = file_io::parameter::POWER;
        kb.max_value = MAX_POWER;
        kb.min_value = MIN_POWER;
        kb.value = status.laser_power;
        break;
    case 1:
        kb.title = file_io::parameter::FREQUENCY;
        kb.max_value = MAX_FREQUENCY;
        kb.min_value = MIN_FREQUENCY;
        kb.value = status.laser_frequency;
        break;
    case 2:
        kb.title = file_io::parameter::RANGE;
        kb.max_value = MAX_SCAN_RANGE;
        kb.min_value = MIN_SCAN_RANGE;
        kb.value = status.scan_width;
        break;
    case 3:
        kb.title = file_io::parameter::RATE;
        kb.max_value = MAX_SCAN_RATE;
        kb.min_value = MIN_SCAN_RATE;
        kb.value = status.scan_frequency;
        break;
    default:
        break;
    }

}

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
    Status_update(charList);
    result = s.c_str();
    std::string cmd =  command.toUtf8().constData();
    cmd.append(sizeof(char), 'a' );
    cmd.append(sizeof(char), 0x0D );
    serialPuts(fd, cmd.c_str() );
    uart_command = "";
    return  result;
}

