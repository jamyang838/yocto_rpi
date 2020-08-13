import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

Window {
    visible: true
    //width: 640
    //height: 480
    title: qsTr("ZNSD")
    //color: "#316B7E"
    color: "#38618c"

    FontLoader {id: font1; source:"qrc:////font/font1.ttf"}

    Connections{
        target: laser
        onStatus_signal: {
            power_Text.text = laser.number2Qstring( power );
            frequency_Text.text = laser.number2Qstring( frequency );
            pulsewidth_Text.text = laser.number2Qstring( pulsewidth );
        }
        onEnable_signal:{
            status_display.opacity =enb? 1: 0.2;
            status_display.enabled = enb;
        }
    }
    //Title***************************************
    Text {
        text: "ZNSD status"
        y: 30
        x: 150
        font.bold: true
        color: "#ffe74c"
        font.pointSize: 30
    }
    Row{
        id: status_display
        y: 90
        Column{
        padding: 20
        spacing: 20

        //Power***************************************
        Row{
            Text {
                text: "POWER(%):"
                width: 200
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: power_Text
                text: "200"
                width: 100
                //color: "#B53F45"
                color: "#ffffff"
                font.pointSize: 20
            }
        }
        //Frequency************************************
        Row{
            Text {
                text: "Frequency(kHz):"
                width: 200
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: frequency_Text
                text: "95"
                width: 100
                color: "#ffffff"
                font.pointSize: 20
            }
        }
        //PulseWidth************************************
        Row{
            Text {
                text: "PulseWdith:"
                width: 200
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: pulsewidth_Text
                text: "95"
                width: 100
                color: "#ffffff"
                font.pointSize: 20
            }
        }
    }

        Rectangle{
            color: "White"
            width: 250
            height: 300
            Column{
                spacing: 20
                Switch {
                    text: qsTr("Modulation EXT")
                    font.pointSize: 15
                }
                Switch {
                    text: qsTr("Modulation EXT")
                    font.pointSize: 15
                }
            }
        }
    }
}
