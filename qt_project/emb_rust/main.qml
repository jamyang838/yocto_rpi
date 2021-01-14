import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Layouts 1.3


ApplicationWindow {
    visible: true
    //title: qsTr("Hello World")

    Material.theme: Material.Dark
    Material.accent: Material.Orange
    /*
    Material.accent: Material.Orange
    Material.primary: Material.Orange
*/

    FontLoader {id: font1; source:"qrc:////font/font1.ttf"}
    Column{
        spacing: 10
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
                            text: "50"
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
                            text: "100"
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
                            text: "8"
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
                            text: "50"
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
                Button{text: "1";width: 100} Button{text: "2";width: 100} Button{text: "3";width: 100}
                Button{text: "4";width: 100} Button{text: "5";width: 100} Button{text: "6";width: 100}
                Button{text: "7";width: 100}
                Button{text: "save"; id: save;width: 100
                    onClicked: save.highlighted = ! save.highlighted
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
