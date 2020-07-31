import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    Rectangle{
    visible: false
    width: 400
    height: 100
    border.color: "Red"
    border.width: 3
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.verticalCenter: parent.verticalCenter
    color: "Red"
    Column{
        width: parent.width
        TextArea{
            text: qsTr("aaabbcc")
            activeFocusOnPress: false
            color: "White"
            width: 200
            font.family: font1
        }
        Button{
            text: qsTr("OK")
            width: parent.width
            onClicked: {messagebox.visible = false}
            anchors.bottomMargin: 5
        }
    }
    }
}
