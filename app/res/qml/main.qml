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
            id: notebookCover
            x: desktopModel.notebook.x
            y: desktopModel.notebook.y
            width: 200
            height: 300
            color: "white"
            rotation: 10

            property point beginDrag
            Drag.active: dragArea.drag.active
            Drag.hotSpot.x: 0
            Drag.hotSpot.y: 0
            Drag.dragType: Drag.Automatic
            Drag.mimeData: {"text/plain": "blabla"}
            Drag.supportedActions: Qt.CopyAction

            // model interface bindinds:
            notebookTitle: desktopModel.notebook.title
            notebookLength: desktopModel.notebook.length
            notebookBackground: desktopModel.notebook.background
            MouseArea{
                id: dragArea
                anchors.fill: parent
                drag.target: parent
                onPressed: {
                    notebookCover.beginDrag = Qt.point(parent.x, parent.y)
                    parent.grabToImage(function(result){
                        parent.Drag.imageSource = result.url
                    })
                }

//                onClicked: {
//                    console.log("showing notebook")
//                    notebook.visible = true
//                }
            }
            Drag.onDragStarted: {
                console.log("started")
            }

            Drag.onDragFinished:{
                console.log("asDDFASF");
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
                    stickyNoteEditor.stickynoteModel = desktopModel.stickynotes[desktopModel.stickynotes.length-1]
                    stickyNoteDialog.open()
                }
            }
        }


        // StickyThumbs
        // StickyNotes (just thumbs, with elided text) positioned around the desktop
        StickyGrid{
            x:300
            y:10
            width: 400
            height: 200

            blockModel: desktopModel.stickynotes
        }

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
            }
        }
    }
}
