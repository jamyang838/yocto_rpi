import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    color: "darkblue"
    title: qsTr("Hello World")

    FontLoader {id: font1; source:"qrc:////font/font1.ttf"}

    Row{
        Slider{
            width: 150
            height: 50
            onValueChanged: {}
        }
        Text {
            text: "ZNSD Laser"
            y: 30
            x: 150
            font.bold: true
            color: "#ffe74c"
            font.pointSize: 30
        }
    }
}
