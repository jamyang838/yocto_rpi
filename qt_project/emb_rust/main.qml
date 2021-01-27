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
        onChange_keyboard: {
            number_area.text =rust.get_kb_value();
            kb_ok.enabled = rust.is_kb_in_range();
            number_area.color = rust.is_kb_in_range()? "white" : "red";
        }
    }

    Column{
        spacing: 10        
        id: main_window        
        DelayButton{
            id: control
            width: parent.width
            height: 30
            text: "Unlocked"
            delay: 1000
            Material.theme : Material.Dark;
            Material.accent: Material.Red
            checked: true;
            onCheckedChanged: {
                rust.button_lock(checked);
                if(checked)
                {
                    text = "Unlocked";
                    Material.theme = Material.Dark;
                }
                else{
                    text = "Locked";
                    Material.theme = Material.Light;
                }
            }
        }
        Row{
            spacing: 50
            GridLayout{
                width: 600
                height: 400
                columns: 2
                //**********************************************
                Button{
                    onClicked:{ if( rust.get_locked() ) return; rust.start_popup(0); label_kb.text = rust.get_kb_title() ; rust.change_keyboard(); popup.open();}
                    Layout.fillHeight: true;Layout.fillWidth: true; contentItem: Column{
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
                    Rectangle{width: 280;height: 5;color: "orange"}}}
                Button{
                onClicked:{if( rust.get_locked() ) return;rust.start_popup(1); label_kb.text = rust.get_kb_title() ; rust.change_keyboard(); popup.open();}
                Layout.fillHeight: true;Layout.fillWidth: true; contentItem: Column{
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
                onClicked:{if( rust.get_locked() ) return;rust.start_popup(3); label_kb.text = rust.get_kb_title() ; rust.change_keyboard(); popup.open();}
                Layout.fillHeight: true;Layout.fillWidth: true;contentItem: Column{
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
                Button{
                onClicked:{ if( rust.get_locked() ) return;
                    rust.start_popup(2);
                    label_kb.text = rust.get_kb_title() ;
                    rust.change_keyboard();
                    popup.open();}
                Layout.fillHeight: true;Layout.fillWidth: true; contentItem: Column{
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
                //**********************************************
            }
            //**********************************************
            Column{
                Label{id:lbe ;text: "Load Recipes:"}
                Button{text: "A";width: 120;id:btn_a;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: {ToolTip.text = rust.get_quick_msg(0); btn_a.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(0);save.highlighted = false;} else{rust.load_recipe(0);} }} }
                Button{text: "B";width: 120;id:btn_b;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: {ToolTip.text = rust.get_quick_msg(1); btn_b.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(1);save.highlighted = false;} else{rust.load_recipe(1);} }}}
                Button{text: "C";width: 120;id:btn_c;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: {ToolTip.text = rust.get_quick_msg(2); btn_c.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(2);save.highlighted = false;} else{rust.load_recipe(2);} }}}
                Button{text: "D";width: 120;id:btn_d;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: { ToolTip.text = rust.get_quick_msg(3);btn_d.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(3);save.highlighted = false;} else{rust.load_recipe(3);} }}}
                Button{text: "E";width: 120;id:btn_e;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: {ToolTip.text = rust.get_quick_msg(4); btn_e.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(4);save.highlighted = false;} else{rust.load_recipe(4);} }}}
                Button{text: "F";width: 120; id: btn_f;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: { ToolTip.text = rust.get_quick_msg(5);btn_f.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(5);save.highlighted = false;} else{rust.load_recipe(5);} }}}
                Button{text: "G";width: 120; id: btn_g;
                    ToolTip.visible: pressed;ToolTip.delay: 500; ToolTip.onVisibleChanged: {ToolTip.text = rust.get_quick_msg(6); btn_g.flat = ToolTip.visible;} onClicked: {if( rust.get_locked() ) return;if(!ToolTip.visible) {if(save.highlighted){
                                rust.save_recipe(6); save.highlighted = false;} else{rust.load_recipe(6);} }}}
                //save********************************
                Button{text: "save"; id: save;width: 120;                    
                    onClicked: {if( rust.get_locked() ) return;
                        save.highlighted = ! save.highlighted;                                                
                    }
                    onHighlightedChanged: {
                        if(highlighted) { lbe.text = "Save Recipes" }
                        else{lbe.text = "Load Recipes"}
                    }
                }
            }
        }
    }
    Popup {
           id: popup
           x: 200
           y: 50
           //width: 500
           //height: parent.height
           modal: true
           focus: true
           closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

          Column{
               TextArea{
                   id: number_area
                   text: "0"
                   font.pointSize: 45
                   horizontalAlignment: "AlignRight"
                   width: parent.width
                   height: 80
                   readOnly: true
               }

               GridLayout {
                   id: grid
                   columns: 4

                   Button {text: "7";onClicked: {rust.insert_keyboard_value(7);rust.change_keyboard(); }}
                   Button {text: "8";onClicked: {rust.insert_keyboard_value(8);rust.change_keyboard(); }}
                   Button {text: "9";onClicked: {rust.insert_keyboard_value(9);rust.change_keyboard(); }}
                   Button {text: "DEL";onClicked: {rust.delete_keyboard_value(); rust.change_keyboard();}}

                   Button {text: "4";onClicked: {rust.insert_keyboard_value(4);rust.change_keyboard(); }}
                   Button {text: "5";onClicked: {rust.insert_keyboard_value(5);rust.change_keyboard(); }}
                   Button {text: "6";onClicked: {rust.insert_keyboard_value(6);rust.change_keyboard(); }}
                   Button {text: "C";onClicked: {  rust.clear_keyboard_value(); rust.change_keyboard(); } }

                   Button {text: "1";onClicked: {rust.insert_keyboard_value(1);rust.change_keyboard(); }}
                   Button {text: "2";onClicked: {rust.insert_keyboard_value(2);rust.change_keyboard(); }}
                   Button {text: "3";onClicked: {rust.insert_keyboard_value(3);rust.change_keyboard(); }}
                   Button {text: "OK";id:kb_ok ;onClicked: {rust.kb_ok(); popup.close();}
                       Layout.rowSpan: 2; Layout.fillHeight: true;}

                   Button {text: "0"; onClicked: {rust.insert_keyboard_value(0);rust.change_keyboard(); }}
                   Button {text: "Cancel" ; Layout.columnSpan: 2 ;onClicked: popup.close()}

               }
               Label{
                   text: "--"
                   id:label_kb
                   font.pointSize: 20
                   horizontalAlignment:"AlignRight"
                   width: parent.width
                   height: 50
               }

           }



       }
}
