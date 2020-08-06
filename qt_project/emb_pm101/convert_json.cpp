#include "convert_json.h"

convert_json::convert_json()
{

}

QString convert_json::get_wlan0_mac()
{
    for(int i=0; i<QNetworkInterface::allInterfaces().count(); i++)
    {
        QNetworkInterface interface = QNetworkInterface::allInterfaces()[i];
        if(interface.name() == "wlan0")
        {
            return  interface.hardwareAddress();
        }
    }
}

QString convert_json::convert_header()
{
    //description
    QString desc = "respberry PI: ";
    desc.append( get_wlan0_mac());
    //start time 2020-05-20T11:18:44.403
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-ddTHH:mm:ss");


    //assembly
    QString result = "{\"desc\":";
    result.append("\"" + desc + "\"");

    result .append(",\"startTime\":");
    result.append("\"" + time + "\"");

    result.append("}");
    qDebug() << result;
    return  result;
}

QString convert_json::convert_detail(int head_id,int ms, double power)
{
    //time(ms)
    //start time 2020-05-20T11:18:44.403
    //assembly
    QString result = "{\"timeMs\":";
    result.append( QString::number(ms) );

    result .append(",\"powervalue\":");
    result.append( QString::number(power) );

    result .append(",\"powerheaderid\":");
    result.append( QString::number(head_id) );

    result.append("}");
    return  result;
}
