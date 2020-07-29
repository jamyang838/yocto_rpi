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
        id: main_display
        width: parent.width
        spacing: 10
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
            padding: 10
            onClicked: { pp.switch1_slot(switch1.checked) }
            background:
                Rectangle {
                gradient: Gradient {
                    GradientStop { position: 0 ; color: "#fff" }
                    GradientStop { position: 1 ; color: "#eee" }
                }}
        }

        Row{
            width: parent.width
            spacing: 10
            Rectangle
            {
                color: "White"
                width: (parent.width / 2) - 5
                height: 150
                Column{
                    TextArea{
                        color: "Black"
                        text: qsTr("Upper Limit")
                    }
                    TextArea{
                        Rectangle{
                            width: parent.width
                            height: parent.height
                            color: "Transparent"

                            border.color: "Red"
                            border.width: 2
                        }
                        color: "Black"
                        text: pp.uplimit

                    }
                    Switch {
                        id: switch2
                        text: qsTr("Upper Limit")
                        onClicked: { pp.switch1_slot(switch1.checked) }
                    }
                    Button{
                        text: "set"
                        onClicked: {
                            pp.is_set_upperlimit = true;
                            num_input.visible = true;
                            main_display.visible = false; }}   }
            }

            Rectangle
            {
                color: "White"
                width: (parent.width / 2) - 5
                height: 150
                Column{
                    TextArea{
                        color: "Black"
                        text: qsTr("Lower Limit")
                    }
                    TextArea{
                        Rectangle{
                            width: parent.width
                            height: parent.height

                            color: "Transparent"
                            border.color: "Red"
                            border.width: 2
                        }
                        color: "Black"
                        text: pp.lowlimit

                    }
                    Switch {
                        id: switch3
                        text: qsTr("Upper Limit")
                        onClicked: { pp.switch1_slot(switch1.checked) }
                    }
                    Button{
                        text: "set"
                        onClicked: {
                            pp.is_set_upperlimit = true;
                            num_input.visible = true;
                            main_display.visible = false; }}   }
            }

        }
    }
    Column{
        id: num_input
        width: parent.width
        visible: false
        TextArea{
            text: pp.limit_display
            color: "White"
            font.pointSize: 30
            height: 60
        }
        Row{
            spacing: 10
            Column{
                spacing: 2
                Row{
                spacing: 2
                Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("1")}
                text: qsTr("1")
                }
                Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("2")}
                text: qsTr("2")
                }
                Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("3")}
                text: qsTr("3")
                }
            }
            Row{
            spacing: 2
            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("4")}
                text: qsTr("4")
            }

            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("5")}
                text: qsTr("5")
            }

            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("6")}
                text: qsTr("6")
            }
            }
            Row{
            spacing: 2
            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("7")}
                text: qsTr("7")
            }

            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("8")}
                text: qsTr("8")
            }

            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("9")}
                text: qsTr("9")
            }
            }
            Row{
            spacing: 2
            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("-")}
                text: qsTr("-")
            }
            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number("0")}
                text: qsTr("0")
            }

            Button{
                width: 80
                height: 80
                onClicked: {pp.input_number(".")}
                text: qsTr(".")
            }
        }

            Row{
                Button{
                    width: 80
                    height: 80
                    onClicked: {pp.input_number("E")}
                    text: qsTr("E")
                }
            }
         }
        Column{
            spacing: 10
            Button{
                text: qsTr("OK")
                onClicked: {
                    pp.input_click("ok")
                    num_input.visible = false;
                    main_display.visible = true;
                }
            }
            Button{
                text: qsTr("CANCEL")
                onClicked: {
                    pp.input_click("cancel")
                    num_input.visible = false;
                    main_display.visible = true;
                }
            }
            Button{
                text: qsTr("ERASE")
                onClicked: {pp.setLimit_display("")}
            }
        }

        Column{
            TextArea{
                text: "Please Input Limit"
                color: "White"
            }
        }
    }
}


    Rectangle{
        id:messagebox
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
