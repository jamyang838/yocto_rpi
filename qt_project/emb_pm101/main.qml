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

        Row{
            Column{
                Rectangle
                {
                    color: "White"
                    width: 200
                    height: 100
                    TextArea{
                        color: "Black"
                        text: qsTr("Upper Limit")
                    }
                    Switch {
                        id: switch2
                        text: qsTr("Upper Limit")
                        padding: 50
                        onClicked: { pp.switch1_slot(switch1.checked) }
                    }
                }


            }
        }
    }

    Column{

        visible: true
        spacing: 2
        Row{
            spacing: 2
            Button{
                width: 100
                height: 100
                text: qsTr("1")
            }
            Button{
                width: 100
                height: 100
                text: qsTr("2")
            }
            Button{
                width: 100
                height: 100
                text: qsTr("3")
            }
        }

        Row{
            spacing: 2
            Button{
                width: 100
                height: 100
                text: qsTr("4")
            }

            Button{
                width: 100
                height: 100
                text: qsTr("5")
            }

            Button{
                width: 100
                height: 100
                text: qsTr("6")
            }
        }
        Row{
            spacing: 2
            Button{
                width: 100
                height: 100
                text: qsTr("7")
            }

            Button{
                width: 100
                height: 100
                text: qsTr("8")
            }

            Button{
                width: 100
                height: 100
                text: qsTr("9")
            }
        }
        Row{
            spacing: 2
            Button{
                width: 100
                height: 100
                onClicked: {pp.input_number("aaa")}
                text: qsTr("0")
            }

            Button{
                width: 100
                height: 100
                text: qsTr(".")
            }

            Button{
                width: 100
                height: 100
                text: qsTr("OK")
            }
        }

    }
}
