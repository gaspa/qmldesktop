import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick.Controls 2.2

ColumnLayout{
    property var page: {}

    RowLayout{
        height: 20
        Text{
            Layout.fillWidth: true
            text: page.date
            anchors.centerIn: parent
        }
        Button{
            text: "date"
            onClicked: {
                pageCalendar.visible = true
            }
        }
        Calendar {
            id: pageCalendar
            visible: false
            minimumDate: new Date(2017, 0, 1)
            maximumDate: new Date(2018, 0, 1)
            onClicked: {
                page.setDate(selectedDate)
                visible = false
            }
        }
    }

    RowLayout{
        height: 20
        TextEdit{
            Layout.fillWidth: true
            text: page.title;
            anchors.centerIn: parent
            onTextChanged: {
                page.setTitle(text)
            }
        }
    }

    Rectangle{
        Layout.fillWidth: true
        Layout.fillHeight: true
        TextEdit{
            text: page.body
            anchors.centerIn: parent
            onTextChanged: {
                page.setBody(text)
            }
        }
    }
}
