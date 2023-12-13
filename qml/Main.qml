import QtQuick 2.15
import QtQuick.Dialogs 1.3
import QtQuick.Window 2.15

import CppObjects 1.0

Window {
    width: 800
    height: 600
    visible: true
    title: qsTr("FSGP Control")

    EthSettings{
        id: _ethSettings

        anchors.fill: parent
        visible: true
    }

    ControlScreen{
        id: _controlScreen

        anchors.fill: parent
        visible: false
    }

    MessageDialog
    {
        id: _msgErrorDialog

       // buttons: MessageDialog.Ok
        title: qsTr("Error")
    }

    Connections{
        target: EthGui

        function onSgErrorMsg(msg)
        {
           _msgErrorDialog.text = msg;
           _msgErrorDialog.open();
        }

        function onSgConnectionOpened()
        {
            console.log("Connection opened");
            _ethSettings.visible = false;
            _controlScreen.visible = true;
        }
    }
}
