import QtQuick
import QtQuick.Controls

ApplicationWindow {
    visible: true
    title: Qt.application.name
    width: 640
    height: 480

    Rectangle {
        anchors.fill: parent
        color: "whitesmoke"

        Label {
            text: qsTr("Hello world!")
            anchors.centerIn: parent
        }
    }
}