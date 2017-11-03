import QtQuick 2.0

Rectangle {
    // model interface
    property color bodyColor: 'yellow'
    property string title:''
    property string body: ''
    function save(){}
    // end interface

    id: stickyNote
    color: bodyColor

    width: 400
    height: 400
    radius: 10

    Rectangle {
        id: titleRectangle
        height: 20
        width: parent.width
        Text{
            id: noteTitle
            text: title
            anchors.centerIn: parent
        }
    }

    Rectangle {
        id: bodyRectangle
        anchors.top: titleRectangle.bottom
        width: parent.width
        TextEdit {
            anchors.fill: parent
            text: body
            textFormat: TextEdit.RichText
        }
    }
}
