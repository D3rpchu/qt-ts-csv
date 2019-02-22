import QtQuick 2.0
import QtQuick.Window 2.11
import Qt.labs.platform 1.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    height: 150
    width: 600

    maximumHeight: height

    minimumHeight: height
    minimumWidth: 500

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
            Layout.fillWidth: true
            anchors.left: b_Source.right
            anchors.verticalCenter: r_Source.verticalCenter
        }

        Button {
            id: b_Source
            height: 25
            Layout.fillWidth: true
            anchors.left: r_Source.left
            anchors.verticalCenter: r_Source.verticalCenter
            text: "Source file"
            onClicked: f_Source.open()
        }

        FileDialog {
            id: f_Source
            title: "Source file"
            nameFilters: ["Excel files (*.xlsx)", "Csv files (*.csv)", "Linguist files (*.ts)"]
            folder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
            onFileChanged: {
                t_Conv.text = ""
                t_Source.text = conv.setSource(f_Source.file)
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
            Layout.fillWidth: true
            anchors.left: cb_Dest.right
            anchors.verticalCenter: r_Dest.verticalCenter
        }

        Button {
            id: b_f_Dest
            height: 25
            Layout.fillWidth: true
            anchors.verticalCenter: r_Dest.verticalCenter
            anchors.left: r_Dest.left
            text: "Destination file"
            onClicked: f_Dest.open()
        }

        FileDialog {
            id: f_Dest
            title: "Destination file"
            nameFilters: ["Excel files (*.xlsx)", "Csv files (*.csv)", "Linguist files (*.ts)"]
            folder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
            onAccepted: {
                t_Conv.text = ""
                t_Dest.text = conv.setDest(f_Dest.file)
                cb_Dest.visible = false
                t_Dest.anchors.left = b_d_Dest.right
            }
        }

        Button {
            id: b_d_Dest
            height: 25
            anchors.verticalCenter: r_Dest.verticalCenter
            anchors.left: b_f_Dest.right
            text: "Destination folder"
            onClicked:d_Dest.open()
            Layout.fillWidth: true
        }

        FolderDialog {
            id: d_Dest
            title: "Destination folder"
            folder: StandardPaths.standardLocations(StandardPaths.DesktopLocation)[0]
            onAccepted: {
                t_Conv.text = ""
                t_Dest.text = conv.setDest(d_Dest.folder + qsTr("/output") +
                                           cb_Dest.currentText)
                cb_Dest.visible = true
                t_Dest.anchors.left = cb_Dest.right
            }
        }

        ComboBox {
            id: cb_Dest
            visible: true
            height: 25
            Layout.fillWidth: true
            anchors.verticalCenter: r_Dest.verticalCenter
            anchors.left: b_d_Dest.right
            model: [".ts", ".csv", ".xlsx"];
            onCurrentTextChanged: {
                t_Dest.text = conv.setDest(d_Dest.folder + qsTr("/output") +
                                           cb_Dest.currentText)
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
            Layout.fillWidth: true
            anchors.left: b_Conv.right
            anchors.verticalCenter: r_Conv.verticalCenter
        }

        Button {
            id: b_Conv
            height: 25
            Layout.fillWidth: true
            anchors.verticalCenter: r_Conv.verticalCenter
            anchors.left: r_Conv.left
            text: "Convert"
            onClicked: t_Conv.text = conv.convert()
        }
    }
}
