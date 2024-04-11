import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    visible: true
    width: 320
    height: 240
    Row {
        anchors.fill: parent
        Rectangle {
            color: "Black"
            width: parent.width / 2
            height: parent.height
            Text {
                font.family: "Arial"
                anchors.centerIn: parent
                text: qsTr("Qt Test")
                font.pointSize: 20
                color: "White"
            }
        }
        Rectangle {
            color: "Pink"
            width: parent.width / 2
            height: parent.height
            Text {
                font.family: "Arial"
                anchors.centerIn: parent
                text: qsTr("First time")
                font.pointSize: 20
                color: "Black"
            }
        }
    }
}
