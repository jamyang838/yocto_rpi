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

    Connections{
        target:  pp
        onUpdate_limitswitch: {
            switch_upperlimit( switch_protect.checked & switch_up.checked );
            switch_lowerlimit( switch_protect.checked & switch_low.checked );
        }
    }
    Connections{
        target: pp
        onShutdown_relay:{
            switch1.checked = false;
            pp.switch1_slot(switch1.checked);
        }
    }

    //Main
    Column{
        id: main_display
        width: parent.width
        padding: 10
        spacing: 10
        TextArea{
            rightPadding: 200
            width: parent.width
            horizontalAlignment: Text.AlignRight
            activeFocusOnPress: false
            text: power_display
            color: "White"
            font.family: font1
            font.pointSize: 50
        }
        //Row 2
        Row{
            Switch //Realy
            {
                id: switch1
                text: qsTr("Relay")
                padding: 10

                onClicked: { pp.switch1_slot(switch1.checked) }
                background:
                    Rectangle {
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: "#fff" }
                        GradientStop { position: 1 ; color: "#eee" }
                    }
                }
            }

            Switch //Switch Protect
            {
                id: switch_protect
                text: qsTr("Protect")
                padding: 10
                onClicked:{ pp.update_limitswitch() }
                background:
                    Rectangle {
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: "#fff" }
                        GradientStop { position: 1 ; color: "#eee" }
                    }
                }
            }
            Switch //Switch Save
            {
                id: switch_save
                text: qsTr("Save")
                padding: 10
                onClicked:{ pp.switch_savefile(switch_save.checked) }
                background:
                    Rectangle {
                    gradient: Gradient {
                        GradientStop { position: 0 ; color: "#fff" }
                        GradientStop { position: 1 ; color: "#eee" }
                    }
                }
            }
        }
        //Row 3
        Row{
            width: parent.width
            spacing: 10
            //upper limit area
            Rectangle
            {
                color: "White"
                opacity: switch_protect.checked&switch_up.checked ? 1: 0.6
                width: (parent.width / 2) - 5
                height: 180
                Column{
                    spacing: 5
                    padding: 5
                    Switch {
                        id: switch_up
                        text: qsTr("Upper Limit")
                        onClicked:{ pp.update_limitswitch() }
                    }
                    Rectangle{
                        width: 150
                        height: 50
                        TextArea{
                            width: parent.width
                            height: parent.height
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                            activeFocusOnPress: false
                            font.pointSize: 16
                            color: "Black"
                            text:  pp.uplimit
                        }
                    }
                    Button{
                        text: "SET"
                        onClicked: {
                            pp.set_is_set_upperlimit(true);
                            num_input.visible = true;
                            main_display.visible = false; }}   }
            }
            //lower limit area
            Rectangle
            {
                color: "White"
                opacity: switch_protect.checked & switch_low.checked ? 1: 0.6
                width: (parent.width / 2) - 5
                height: 180
                Column{
                    spacing: 5
                    padding: 5
                    Switch {
                        id: switch_low
                        text: qsTr("Lower Limit")
                        onClicked:{ pp.update_limitswitch() }
                    }
                    Rectangle{
                        width: 150
                        height: 50
                        TextArea{
                            width: parent.width
                            height: parent.height
                            horizontalAlignment: Text.AlignRight
                            verticalAlignment: Text.AlignVCenter
                            activeFocusOnPress: false
                            font.pointSize: 16
                            color: "Black"
                            text: pp.lowlimit
                        }
                    }
                    Button{
                        text: "SET"
                        onClicked: {
                            pp.set_is_set_upperlimit(false);
                            num_input.visible = true;
                            main_display.visible = false; }}   }
            }
        }
    }
    //Number input
    Column{
        id: num_input
        width: parent.width
        visible: false
        TextArea{
            text: pp.limit_display
            color: "White"
            activeFocusOnPress: false
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
                activeFocusOnPress: false
                color: "White"
            }
        }
    }
}
    //Message
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
