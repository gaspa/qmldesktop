import QtQuick 2.0

Rectangle {
    // model interface
    property color bodyColor: 'red'
    property string title:''
    property string body: ''
    function save(){}
    // end interface

    id: stickyNote
    color: bodyColor

    width: 100
    height: 100
    radius: 10

    Rectangle {
        id: titleRectangle
        height: 20
        width: parent.width
        Text{
            id: noteTitle
            text: title
        }
    }

    Rectangle {
        id: bodyRectangle
        anchors.top: titleRectangle.bottom
        width: parent.width
        TextEdit {
            anchors.fill: parent
            text: body
            focus: true
        }
    }
}
