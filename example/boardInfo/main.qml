import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
ApplicationWindow {
    visible: true
    width: 320
    height: 240
    header: Rectangle {
        width: parent.width
        height: 30
        color: "yellow"
        Text {
            anchors.centerIn: parent
            font {
                pointSize: 15
                bold: true
            }
            text: "BOARD INFO"
        }
        border {
            width: 3
            color: "Black"
        }
    }
    
    Column {
        anchors.fill: parent
        Row {
            width: parent.width
            height: parent.height / 2
            Column {
                width: parent.width / 3
                height: parent.height
                Rectangle {
                    width: parent.width
                    height: parent.height / 3
                    color: "yellow"
                    Text {
                        id: total
                        anchors.centerIn: parent
                        font {
                            pointSize: 10
                            family: "Arial"
                            italic: true
                        }
                        color: "Black"
                    }
                }
                Rectangle {
                    width: parent.width
                    height: parent.height / 3
                    color: "Grey"
                    Text {
                        id: free
                        anchors.centerIn: parent
                        font {
                            pointSize: 10
                            family: "Arial"
                            italic: true
                        }
                        color: "Black"
                    }
                }
                Rectangle {
                    width: parent.width
                    height: parent.height / 3
                    color: "brown"
                    Text {
                        id: used
                        anchors.centerIn: parent
                        font {
                            pointSize: 10
                            family: "Arial"
                            italic: true
                        }
                        color: "Black"
                    }
                }
            }
            Rectangle {
                width: parent.width / 3
                height: parent.height
                color: "pink"
                Text {
                    id: kernelVersion
                    anchors.centerIn: parent
                    font {
                        pointSize: 10
                        family: "Arial"
                        italic: true
                    }
                    color: "Black"
                }
            }
            Column {
                width: parent.width / 3
                height: parent.height
                Rectangle {
                    width: parent.width
                    height: parent.height / 2
                    color: "red"
                    Text {
                        id: wall_time
                        anchors.centerIn: parent
                        font {
                            pointSize: 10
                            family: "Arial"
                            italic: true
                        }
                        color: "Black"
                    }
                }
                Rectangle {
                    width: parent.width
                    height: parent.height / 2
                    color: "blue"
                    Text {
                        id: system_up_time
                        anchors.centerIn: parent
                        font {
                            pointSize: 10
                            family: "Arial"
                            italic: true
                        }
                        color: "Black"
                    }
                }
            }
        }
        Row {
            width: parent.width
            height: parent.height / 2
            Rectangle {
                width: parent.width
                height: parent.height
                color: "Beige"
                Text {
                    id: board_name
                    anchors.centerIn: parent
                    font {
                        pointSize: 13
                        family: "Arial"
                        italic: true
                    }
                    color: "Black"
                }
            }
        }
    }
    Connections {
        target: Board
        function onTimeChanged(h, m, s) {
            wall_time.text = h + ":" + m + ":" + s
        }
        function onSystimeChanged(h, m, s) {
            system_up_time.text = h + ":" + m + ":" + s
        }

        function onCpuChanged(t, f, u) {
            total.text = "Total: " + t.toFixed(2) + "Gb"
            free.text = "Free: " + f.toFixed(2) + "Gb"
            used.text = "Used: " + u.toFixed(2) + "%"
        }
        function onNameChanged(name) {
            board_name.text = name
        }
        function onKversionChanged(version)
        {
            kernelVersion.text = "Kernel version\n" + version
        }
    }
}
