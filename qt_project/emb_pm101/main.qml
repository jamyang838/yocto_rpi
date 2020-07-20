import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    color: "black"
    title: qsTr("Hello World")

    Column{

    }
    Image {
        source: "/pic/frame.png"
        width: 500
        fillMode: Image.PreserveAspectFit
    }
}
