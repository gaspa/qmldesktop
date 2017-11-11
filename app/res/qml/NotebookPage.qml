import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as C1
import QtQuick.Controls 2.2

ColumnLayout{
    property var page: ({})


    RowLayout{
        height: 20
        Layout.margins: 5

        Text{
            Layout.fillWidth: true
            text: page.date
            anchors.centerIn: parent
        }
        Button{
            text: "date"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                calendarDialog.open()
            }
        }

        Dialog{
            id: calendarDialog
            title: "Date"
            parent: ApplicationWindow.overlay
            modal: true
            standardButtons: Dialog.Close

            x: (parent.width - width) / 2
            y: (parent.height - height) / 2

            C1.Calendar{
                id: calendarObject
                anchors.fill: parent
                minimumDate: new Date(2017, 0, 1)
                onClicked: {
                    page.date = selectedDate
                    calendarDialog.close()
                }
            }
        }
    }

    RowLayout{
        height: 20
        Layout.margins: 5

        TextEdit{
            id: titleTextEdit
            Layout.fillWidth: true
            text: page.title;
            anchors.centerIn: parent
            onEditingFinished: {
                page.title = text
            }

            property string placeholderText: "Enter new title here..."
            Text {
                text: titleTextEdit.placeholderText
                color: "#aaa"
                visible: !titleTextEdit.text
            }
        }
    }

    Rectangle{
        Layout.fillWidth: true
        Layout.fillHeight: true
        TextEdit{
            id: bodyTextEdit
            text: page.body
            anchors.fill: parent
            textMargin: 10
            onEditingFinished: {
                page.body = text
            }

            property string placeholderText: "Enter new text here..."
            Text {
                text: bodyTextEdit.placeholderText
                color: "lightgrey"
                visible: !bodyTextEdit.text
                anchors.centerIn: parent
            }
        }
    }
}
