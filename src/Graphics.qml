import QtQuick 2.0
import QtQuick.Window 2.12
import Qt.labs.platform 1.1
import QtQuick.Controls 2.5

Window {
    height: 150
    width: 500
    visible: true
    title: qsTr("Converter")

    Rectangle {
        id: r_Source
        x: 0
        y: 0
        width: 500
        height: 50

        Text {
            id: t_Source
            height: 25
            width: 50
            anchors.left: b_Source.right
            anchors.verticalCenter: r_Source.verticalCenter
        }

        Button {
            id: b_Source
            height: 25
            width: 50
            anchors.left: r_Source.left
            anchors.verticalCenter: r_Source.verticalCenter
            text: "Scegli"
            onClicked: f_Source.open()
        }

        FileDialog {
            id: f_Source
            title: "Source"
            folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            onFileChanged: {
                t_Conv.text = ""
                t_Source.text = f_Source.file
            }
        }
    }

    Rectangle {
        id: r_Dest
        anchors.top: r_Source.bottom
        width: 500
        height: 50

        Text {
            id: t_Dest
            height: 25
            width: 50
            anchors.left: b_Dest.right
            anchors.verticalCenter: r_Dest.verticalCenter
        }

        Button {
            id: b_Dest
            height: 25
            width: 50
            anchors.verticalCenter: r_Dest.verticalCenter
            anchors.left: r_Dest.left
            text: "Scegli"
            onClicked: f_Dest.open()
        }

        FileDialog {
            id: f_Dest
            title: "Destination"
            folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
            onFileChanged: {
                t_Conv.text = ""
                t_Dest.text = f_Dest.file
            }
        }
    }

    Rectangle {
        id: r_Conv
        anchors.top: r_Dest.bottom
        width: 500
        height: 50

        Text {
            id: t_Conv
            height: 25
            width: 50
            anchors.left: b_Conv.right
            anchors.verticalCenter: r_Conv.verticalCenter
        }

        Button {
            id: b_Conv
            height: 25
            width: 50
            anchors.verticalCenter: r_Conv.verticalCenter
            anchors.left: r_Conv.left
            text: "Scegli"
            onClicked: t_Conv.text = conv.convert(t_Source.text, t_Dest.text)
        }
    }
}

