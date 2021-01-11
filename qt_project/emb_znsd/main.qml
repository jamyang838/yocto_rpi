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
            if(laser.get_update_delay() ) return;
            power_Text.text = laser.number2Qstring( power );
            frequency_Text.text = laser.number2Qstring( frequency );
            pulsewidth_Text.text = laser.number2Qstring( pulsewidth );
            ext_switch.checked = ext;
            modulation_switch.checked = modulation;
            guidelaser_switch.checked = guide_laser;
            coded_switch.checked = coded;
            key = true;
            key_led.color = key? "#77e647" : "#ff7878";
            warning_Text.text = laser.get_alarmString(warning);
            if(warning!=0)
            {
                warning_Text.color = "#ff7878";
            }
            else
            {
                warning_Text.color = "#77e647";
            }
        }
        onEnable_signal:{            
            status_display.opacity =enb? 1: 0.2;
            status_display.enabled = enb;
        }
    }
    //Title***************************************
    Text {
        text: "ZNSD Laser"
        y: 30
        x: 150
        font.bold: true
        color: "#ffe74c"
        font.pointSize: 30
    }
    Row{
        id: status_display
        y: 90
        //Left Column***************************************
        Column{
        padding: 20
        spacing: 20

        //Power***************************************
        Row{
            Text {
                text: "POWER(%):"
                width: 230
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: power_Text
                text: "--"
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
                width: 230
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: frequency_Text
                text: "--"
                width: 100
                color: "#ffffff"
                font.pointSize: 20
            }
        }
        //PulseWidth************************************
        Row{
            Text {
                text: "PulseWdith:"
                width: 230
                color: "#ffe74c"
                font.pointSize: 20
            }
            Text {
                id: pulsewidth_Text
                text: "--"
                width: 100
                color: "#ffffff"
                font.pointSize: 20
            }
        }
        //PulseWidth************************************
        /*
            Text {
                text: "STATUS:"
                width: 230
                color: "#ffe74c"
                font.pointSize: 20
            }
            */
        Text {
                id: warning_Text
                text: "--"
                width: 100
                color: "#ffffff"
                font.pointSize: 10
            }
        Slider{
            width: 150
            height: 50
            onValueChanged: {}
        }
        }
        //Right Column**************************************
        Rectangle{
            color: "White"
            width: 250
            height: 300
            Column{
                y: 20
                spacing: 15
                Row{
                    x: 5
                    spacing: 10
                    Rectangle{
                        id: key_led
                        width: 50
                        height: 20
                        radius: 5
                        color: "red"
                    }
                    Text {
                        text: qsTr("Key")
                        font.pointSize: 15
                    }
                }

                Switch {
                    id:ext_switch
                    text: qsTr("Modulation EXT")
                    font.pointSize: 15
                    onClicked: {
                        laser.command_signal(ext_switch.checked?"$51;1":"$51;0" );
                    }
                }
                Switch {
                    id: modulation_switch
                    text: qsTr("Modulation ON")
                    font.pointSize: 15
                    onClicked: {
                        laser.command_signal(modulation_switch.checked?"$52;1":"$52;0" );
                    }
                }
                Switch {
                    id: guidelaser_switch
                    text: qsTr("Guide Laser")
                    font.pointSize: 15                    
                    onClicked: {
                        laser.command_signal(guidelaser_switch.checked?"$53;1":"$53;0" );
                    }
                }                
                Switch {
                    id: coded_switch
                    text: qsTr("Adv Mode")
                    font.pointSize: 15
                    onClicked: {
                        laser.command_signal(coded_switch.checked?"$54;1":"$54;0" );
                    }
                }
            }
        }        
    }
    Text{
        text: "v1.11\nITRI M200"
        color: "white"
        anchors.fill: parent
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignBottom
        anchors.rightMargin: 5
        anchors.bottomMargin: 5
    }
}
