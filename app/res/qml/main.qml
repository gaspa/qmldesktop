import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


ApplicationWindow {

    Shortcut {
        sequence: StandardKey.Quit
        context: Qt.ApplicationShortcut
        onActivated: Qt.quit()
    }

    id: appWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("Desktop")

    Rectangle{
        id: desktop
        color: "grey"
        anchors.fill: parent

        Image {
            id: desktop_background
            source: desktopModel.background
            anchors.fill: parent
            fillMode: Image.Tile
            verticalAlignment: Image.AlignTop
            horizontalAlignment: Image.AlignLeft
        }

        // ClosedNotebook
        // closed notebook image, clickin on it will open the NoteBook.qml delegate
        NotebookCover {
            x: 50
            y: 50
            width: 200
            height: 300
            rotation: 10
            // model interface bindinds:
            notebookTitle: desktopModel.notebook.title
            notebookLength: desktopModel.notebook.length
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("showing notebook")
                    notebook.visible = true
                }
            }
        }


        // StickyBlock
        // draw a block of stickynoes.
        StickyBlock{
            x: 500
            y: 300
            width: 100
            height: 100
            rotation: -20
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    console.log("showing new sticky note")
                    desktopModel.addStickyNote()
                    stickyNoteEditor.stickynoteModel = desktopModel.stickynotes[0]
                    stickyNoteDialog.open()
                }
            }
        }


        // StickyThumbs
        // StickyNotes (just thumbs, with elided text) positioned around the desktop
//        Repeater{
//            model: desktopModel.stickynotes
//            StickyNote{
//                stickynoteModel: modelData
//                isEditor: false
//                width: 200
//                height: 200
//                rotation: index*10
//            }
//        }


        // Notebook:
        Notebook{
            id: notebook
            visible: false
            anchors.fill: parent
            notebookModel: desktopModel.notebook
        }

        Dialog{

            id: stickyNoteDialog
            parent: ApplicationWindow.overlay
            x: (parent.width - width) / 2
            y: (parent.height - height) / 2
            closePolicy: Popup.CloseOnEscape

            modal: true

            StickyNote{
                id: stickyNoteEditor
                isEditor: true
                anchors.centerIn: parent
                stickynoteModel: stickynoteModel
            }
        }
    }
}
