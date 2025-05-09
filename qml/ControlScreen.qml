import QtQuick 2.15
import QtQuick.Controls 2.15

import QtQuick.Layouts 1.15

import CppObjects 1.0

Item {
    Column{
        anchors.fill: parent
        anchors.margins: width/50
        spacing: height/75

        Rectangle{
            height: parent.height*0.15
            width: parent.width

            radius: width/50
            border.width: 1
            Column{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: height/50

                Label{
                    // height: parent.height/3

                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Код частоты:"
                }

                SpinBox{
                    id: _nkchSpinBox

                    // height: parent.height/3
                    anchors.horizontalCenter: parent.horizontalCenter

                    from: 1
                    to: 100

                    editable: true

                    //inputMethodHints: Qt.ImhDigitsOnly
                }
            }          
        }

        Rectangle{
            height: parent.height*0.2
            width: parent.width

            radius: width/50
            border.width: 1
            Column{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                spacing: height/50

                Label{
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Код пачки:"
                }

                SpinBox{
                    id: _kinematicSpinBox

                    from: 0
                    to: 196

                    value: 16

                    anchors.horizontalCenter: parent.horizontalCenter
                    editable: true

                    //inputMethodHints: Qt.ImhDigitsOnly
                }

                CheckBox{
                    id: _nlchmCheckBox

                    // height: parent.height/3
                    anchors.horizontalCenter: parent.horizontalCenter

                    text: "Положительный наклон"

                    checked: true
                }
            }
        }

        Rectangle{
            height: parent.height*0.3
            width: parent.width

            radius: width/50
            border.width: 1

            GridLayout{
                anchors.fill: parent


                Column{
                    Layout.alignment: Qt.AlignHCenter
                    Label{
                        text: "Тип пилот сигнала"
                    }
                    ComboBox{
                        id: _PS_tipCombo

                        textRole: "key"
                        model: ListModel{
                            ListElement{key: "Выкл."; value: 0}
                            ListElement{key: "Монохром."; value: 1}
                            ListElement{key: "ШПС"; value: 2}
                            ListElement{key: "ЛЧМ"; value: 3}
                        }
                    }
                }

                Column{
                    Layout.alignment: Qt.AlignHCenter
                    Label{
                        text: "Полоса пилот сигнала"
                    }

                    ComboBox{
                        id: _PS_polosaCombo

                        textRole: "key"
                        model: ListModel{
                            ListElement{key: "2 МГц"; value: 0}
                            ListElement{key: "5 МГц"; value: 1}
                            ListElement{key: "10 МГц"; value: 2}
                            ListElement{key: "20 МГц"; value: 3}
                        }
                    }
                }

                Column{
                    Layout.alignment: Qt.AlignHCenter
                }
            }
        }

        Rectangle{
            height: parent.height*0.15
            width: parent.width

            radius: width/50
            border.width: 1
            Column{
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                anchors.margins: width/5
                spacing: height/10

                Label{
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Статус:"
                }

                Label{
                    id: _labelFrameSend

                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "--------"
                }

                Label{
                    id: _labelAckRecieved

                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "--------"
                }
            }
        }

        Item{
            height: parent.height*0.15
            width: parent.width

            Button{
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Запись"

                onClicked: {
                    CtrlGui.NKCH = _nkchSpinBox.value;
                    CtrlGui.KP = _kinematicSpinBox.value;

                    CtrlGui.PS_type = _PS_tipCombo.currentIndex;
                    CtrlGui.PS_polosa = _PS_polosaCombo.currentIndex;

                    CtrlGui.NLCHM = _nlchmCheckBox.checked;

                    CtrlGui.sendFrame()

                    _labelFrameSend.text = Qt.formatTime(new Date(), "hh:mm:ss") + " <== Кадр отправлен";
                    _labelAckRecieved.text = "--------"
                }
            }
        }
    }

    Connections{
        target: CtrlGui

        function onSgAckRecieved()
        {
             _labelAckRecieved.text = Qt.formatTime(new Date(), "hh:mm:ss") + " ==> Подтверждение получено";
        }
    }
}
