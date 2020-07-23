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
        width: parent.width
        spacing: 50        
        TextArea{
            rightPadding: 200
            width: parent.width
            horizontalAlignment: Text.AlignRight
            text: power_display
            color: "White"
            font.family: font1
            font.pointSize: 50
        }
        Button{
            text: qsTr("Test")
            onClicked: { console.log("Button") }
            width: 100
            height: 100
        }

        Switch {
            id: switch1
            text: qsTr("Relay")
            padding: 50
            onClicked: { pp.switch1_slot(switch1.checked) }
            background:
                Rectangle {
                border.color: "red"
                border.width: 5
                gradient: Gradient {
                    GradientStop { position: 0 ; color: "#fff" }
                    GradientStop { position: 1 ; color: "#eee" }
                }}
        }
    }
}
