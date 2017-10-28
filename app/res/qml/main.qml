import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

// idea:
// * desktopObject / desktopModel che contiene tutto il resto
// * StickyBlock, blcco di postit. -> stickyNote ch
// * diary uno solo.


ApplicationWindow {

    ListModel{
        id: stickyblockmodel
        ListElement {bodyColor: 'yellow'; title: 'new note'; body: '...'}
        ListElement {bodyColor: 'orange'; title: 'new note2 '; body: 'asdfasdffa'}
    }

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


    ColumnLayout
    {
        anchors.fill: parent

        RowLayout
        {
            id: buttonsRow
            Layout.fillWidth: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
            anchors.top: parent.top

            Button {
                id: diaryButton
                text: qsTr("Diary")
                onClicked: {
                    console.log("diary button Pressed. should show diary");
                }
            }
            Button {
                id: stickyBlockButton
                text: qsTr("StickyBlock")
                onClicked: {
                    stickyBlock.visible = !stickyBlock.visible;
                }
            }
        }

        Rectangle{
            id: desktop
            color: "grey"
            Layout.fillWidth: true
            Layout.fillHeight: true

            Image {
                id: desktop_background
                source: desktopModel.background

                anchors.fill: parent
            }

            // ClosedNotebook
            // closed notebook image, clickin on it will open the NoteBook.qml delegate
            ClosedNotebook{
                x: 50
                y: 50
                width: 200
                height: 80
                rotation: 10
                notebookTitle: desktopModel.notebook.title
                notebookLength: desktopModel.notebook.length
            }

            // StickyBlock
            // draw a block of stickynoes.


            // StickyThumbs
            // StickyNotes (just thumbs, with elided text) positioned around the desktop


        }

    }

}
