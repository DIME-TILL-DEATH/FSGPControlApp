import QtQuick 2.15
import QtQuick.Controls 2.15

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
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: "Код частоты:"
                }

                SpinBox{
                    id: _nkchSpinBox

                    from: 1
                    to: 45

                    editable: true

                    //inputMethodHints: Qt.ImhDigitsOnly
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
