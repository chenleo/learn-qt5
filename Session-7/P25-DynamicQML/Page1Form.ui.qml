import QtQuick 2.9
import QtQuick.Controls 2.2

Page {
    id: page
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }

    TextField {
        id: textField
        x: 235
        y: 51
        width: 176
        height: 34
    }

    Text {
        id: element
        x: 235
        y: 252
        width: 251
        height: 38
        text: textField.text
        textFormat: Text.PlainText
        font.family: "Arial"
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 12
    }
}
