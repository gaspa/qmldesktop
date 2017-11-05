import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2

ColumnLayout {
    // model interface
    property var stickynoteModel: ({})
    property bool isEditor: false
    // end interface

    id: stickyNote

    width: 400
    height: 400
//    radius: 10

    RowLayout{
        id: buttonRow
        visible: isEditor
        RoundButton{
            id: redColorSelect
            text: "red"
            onClicked: { stickynoteModel.color = "red" }
        }
        RoundButton {
            text: "yellow"
            onClicked: { stickynoteModel.color = "yellow" }

        }
        Button {
            text: "save"
            onClicked: {
                console.log("save clicked")
                desktopModel
            }
        }
    }

    Rectangle {
        id: titleRectangle
        height: 20
        width: parent.width
        TextEdit{
            id: noteTitle
            text: stickynoteModel.title
            anchors.centerIn: parent
            onTextChanged: {
                stickynoteModel.title = text
            }

            property string placeholderText: "Enter new title here..."
            Text {
                text: noteTitle.placeholderText
                color: "#aaa"
                visible: !noteTitle.text
            }
        }
    }

    Rectangle {
        id: bodyRectangle
        anchors.top: titleRectangle.bottom
        width: parent.width
        Layout.fillHeight: true
        color: stickynoteModel.color
        TextEdit {
            id: stickynoteBodyText
            anchors.fill: parent
            text: stickynoteModel.body
//            textFormat: TextEdit.RichText
            onTextChanged: {
                stickynoteModel.body = text
            }

            property string placeholderText: "Enter new text here..."
            Text {
                text: stickynoteBodyText.placeholderText
                color: "#aaa"
                visible: !stickynoteBodyText.text
                anchors.centerIn: parent
            }
        }
    }
}
