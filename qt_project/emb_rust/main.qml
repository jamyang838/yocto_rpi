import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3


ApplicationWindow {
    visible: true    
    Material.theme: Material.Dark
    Material.accent: Material.Orange

    FontLoader {id: font1; source:"qrc:////font/font1.ttf"}

    Connections{
        target: rust;
        onStatus_signal: {
            label_power.text =rust.get_status_power();
            label_frequency.text = rust.get_status_frequency();
            label_rate.text = rust.get_status_rate();
            label_range.text = rust.get_status_range();
        }
        onEnable_signal: {
            if(enb){ main_window.opacity = 1;}
            else{main_window.opacity = 0.2;
            }
        }
    }

    Column{
        spacing: 10
        id: main_window
        Label{text: ""; font.pointSize: 30; width: 640; horizontalAlignment: "AlignHCenter"; height: 30}
        Row{
            spacing: 50
            GridLayout{
                width: 600
                height: 400
                columns: 2
                //**********************************************
                Button{
                    onClicked: popup.open(); Layout.fillHeight: true;Layout.fillWidth: true;
                    contentItem: Column{
                    anchors.bottom: parent.bottom
                    Label{
                        Layout.fillWidth: true
                        text: "POWER"
                        font.pointSize: 20
                        horizontalAlignment: "AlignHCenter"
                    }
                    Row{
                        spacing: 20
                        Label{
                            id:label_power
                            //text: "50"
                            font.pointSize: 40
                            width: 200
                            horizontalAlignment: "AlignRight"
                        }
                        Label{
                            text: "%"
                            font.pointSize: 20
                        }
                    }
                    Rectangle{
                        width: 280
                        height: 5
                        color: "orange"
                    }
                }
            }
                Button{
                onClicked: popup.open(); Layout.fillHeight: true;Layout.fillWidth: true;
                contentItem: Column{
                    anchors.bottom: parent.bottom
                    Label{
                        Layout.fillWidth: true
                        text: "FREQUENCY"
                        font.pointSize: 20
                        horizontalAlignment: "AlignHCenter"
                    }
                    Row{
                        spacing: 20
                        Label{
                            //text: "100"
                            id:label_frequency
                            font.pointSize: 40
                            width: 200
                            horizontalAlignment: "AlignRight"
                        }
                        Label{
                            text: "Hz"
                            font.pointSize: 20
                        }
                    }
                    Rectangle{
                        width: 280
                        height: 5
                        color: "orange"
                    }
                }
            }
                Button{
                onClicked: popup.open(); Layout.fillHeight: true;Layout.fillWidth: true;
                contentItem: Column{
                    anchors.bottom: parent.bottom
                    Label{
                        Layout.fillWidth: true
                        text: "SCAN RANGE"
                        font.pointSize: 20
                        horizontalAlignment: "AlignHCenter"
                    }
                    Row{
                        spacing: 20
                        Label{
                            //text: "8"
                            id:label_range
                            font.pointSize: 40
                            width: 200
                            horizontalAlignment: "AlignRight"
                        }
                        Label{
                            text: "cm"
                            font.pointSize: 20
                        }
                    }
                    Rectangle{
                        width: 280
                        height: 5
                        color: "orange"
                    }
                }
            }
                Button{
                onClicked: popup.open(); Layout.fillHeight: true;Layout.fillWidth: true;
                contentItem: Column{
                    anchors.bottom: parent.bottom
                    Label{
                        Layout.fillWidth: true
                        text: "SCAN RATE"
                        font.pointSize: 20
                        horizontalAlignment: "AlignHCenter"
                    }
                    Row{
                        spacing: 20
                        Label{
                            //text: "50"
                            id:label_rate
                            font.pointSize: 40
                            width: 200
                            horizontalAlignment: "AlignRight"
                        }
                        Label{
                            text: "Hz"
                            font.pointSize: 20
                        }
                    }
                    Rectangle{
                        width: 280
                        height: 5
                        color: "orange"
                    }
                }
                }
                //**********************************************
            }
            //**********************************************
            Column{
                Label{id:lbe ;text: "Load Recipes:"}
                Button{text: "A";width: 120; onClicked: if(save.highlighted){rust.save_recipe(0);} else{rust.load_recipe(0);} }

                Button{text: "B";width: 120} Button{text: "C";width: 120}
                Button{text: "D";width: 120} Button{text: "E";width: 120} Button{text: "F";width: 120}
                Button{text: "G";width: 120;
                    onClicked: lbe.text = "1"
                    ToolTip.visible: pressed
                    ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
                    ToolTip.text: "aaa"
                }
                Button{text: "save"; id: save;width: 120;
                    onClicked: {
                        save.highlighted = ! save.highlighted;
                        if(save.highlighted)
                        {
                            lbe.text = "Save Recipes"
                        }
                        else{lbe.text = "Load Recipes"}
                    }
                }
            }
        }
    }
       Popup {
           id: popup
           //width: 500
           //height: parent.height
           modal: true
           focus: true
           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

          Column{
               TextArea{
                   text: "1234"
                   font.pointSize: 45
                   horizontalAlignment: "AlignRight"
                   width: parent.width
                   height: 80
                   readOnly: true
               }

               GridLayout {
                   id: grid
                   columns: 4

                   Button {text: "7";onClicked: popup.open();}
                   Button {text: "8";onClicked: popup.open();}
                   Button {text: "9";onClicked: popup.open();}
                   Button {text: "DEL";onClicked: popup.open();}

                   Button {text: "4";onClicked: popup.open();}
                   Button {text: "5";onClicked: popup.open();}
                   Button {text: "6";onClicked: popup.open();}
                   Button {text: "C";onClicked: popup.open(); }

                   Button {text: "1";onClicked: popup.open();}
                   Button {text: "2";onClicked: popup.open();}
                   Button {text: "3";onClicked: popup.open();}
                   Button {text: "OK";onClicked: popup.close();
                       Layout.rowSpan: 2; Layout.fillHeight: true;}

                   Button {text: "0";onClicked: popup.open();}
                   Button {text: "Cancel";onClicked: popup.open();}

               }
               Label{
                   text: "POWER"
                   font.pointSize: 20
                   horizontalAlignment:"AlignRight"
                   width: parent.width
                   height: 50
               }

           }



       }
}
