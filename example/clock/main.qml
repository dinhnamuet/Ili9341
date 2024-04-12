import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
ApplicationWindow {
    visible: true
    width: 320
    height: 240
    header: Rectangle {
        width: parent.width
        height: 50
        border {
            width: 3
            color: "black"
        }

        Text {
            anchors.centerIn: parent
            font {
                pointSize: 20
                family: "Timesnewroman"
                bold: true
                italic: true
            }
            color: "Orange"
            text: "Qt Clock"
        }
    }
    Rectangle {
        anchors.fill: parent
        Text {
            id: wall_time
            anchors.centerIn: parent
            font {
                pointSize: 20
                family: "Arial"
                italic: true
            }
            color: "Black"
        }
    }
    Connections {
        target: Clock
        function onTimeChanged(h, m, s) {
            wall_time.text = "Time: " + h + ":" + m + ":" + s
        }
    }
}
