import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3

Window {
    visible: true
    width: 640
    height: 480
    color: "black"
    title: qsTr("Hello World")

    FontLoader {id: font1; source:"qrc:////font/font1.ttf"}

    Column{
        spacing: 50
        TextArea{
            text: power_display
            color: "White"
            font.family: font1
            font.pointSize: 30
        }
    }
    Image {
        source: "/pic/frame.png"
        width: 500
        fillMode: Image.PreserveAspectFit
    }
}
