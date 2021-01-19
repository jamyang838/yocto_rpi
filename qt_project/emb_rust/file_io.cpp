#include "file_io.h"


file_io::file_io()
{
    initial_recipes();    
}

int file_io::get_value(int index, file_io::parameter p)
{
    int value = jsonArray[index].toObject().take(convert_parameter_tostring(p)).toInt();
    file_io::is_valid(p, value);
    return  value;
}

void file_io::save_recipes()
{
    QJsonDocument doc(jsonArray);
    QString strJson(doc.toJson());

    std::ofstream ofs(FILE_NAME);
    ofs << strJson.toStdString().data();
    ofs.close();

    get_Jsonfile();
}

void file_io::initial_recipes()
{
    for(int i=0; i <10; i++)
    {
        QJsonObject _jsonObj;
        _jsonObj.insert(convert_parameter_tostring(parameter::POWER), DEF_POWER);
        _jsonObj.insert(convert_parameter_tostring(parameter::FREQUENCY), DEF_FREQUENCY);
        _jsonObj.insert(convert_parameter_tostring(parameter::RATE), DEF_SCAN_RATE);
        _jsonObj.insert(convert_parameter_tostring(parameter::RANGE), DEF_SCAN_RANGE);

        jsonArray.append(_jsonObj);
    }

    if(QFileInfo(FILE_NAME).exists()){
        //The file exists
        get_Jsonfile();
    }
    else{
        save_recipes();
    }
}

void file_io::update_recipe(int index, int power, int frequency, int rate, int range)
{
    QJsonArray _array;
    for(int i=0; i <10; i++)
    {
        QJsonObject _obj;
        if(i == index)
        {
           _obj.insert(convert_parameter_tostring(parameter::POWER), power);
            //_obj.insert(convert_parameter_tostring(parameter::POWER), 777);
           _obj.insert(convert_parameter_tostring(parameter::FREQUENCY), frequency);
           _obj.insert(convert_parameter_tostring(parameter::RATE), rate);
           _obj.insert(convert_parameter_tostring(parameter::RANGE), range);
        }
        else{
            _obj = jsonArray[i].toObject();

        }
        _array.append(_obj);
    }
    jsonArray.swap(_array);
}

bool file_io::is_valid(parameter p, int value)
{
    switch (p) {
    case POWER:
        return (value >= MIN_POWER) && (value <= MAX_POWER );
        break;
    case FREQUENCY:
        return (value >= MIN_FREQUENCY) && (value <= MAX_FREQUENCY );
        break;
    case RATE:
        return (value >= MIN_SCAN_RATE) && (value <= MAX_SCAN_RATE );
        break;
    case RANGE:
        return (value >= MIN_SCAN_RANGE) && (value <= MAX_SCAN_RANGE );
        break;
    default:
        return false;
        break;
    }
}

QString file_io::convert_parameter_tostring(parameter p)
{
    QString result;
    switch (p) {
    case POWER:
        result = "power";
        break;
    case FREQUENCY:
        result = "frequency";
        break;
    case RATE:
        result = "rate";
        break;
    case RANGE:
        result = "range";
        break;
    default:
        break;
    }
    return result;
}

void file_io::get_Jsonfile()
{
    QFile savefile(FILE_NAME);
    savefile.open(QIODevice::ReadOnly);
    QTextStream in(&savefile);
    QString strReply = in.readAll();
    QStringList propertyNames;
    QStringList propertyKeys;
    //QString strReply = (QString)reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
    jsonArray = jsonResponse.array();
}
