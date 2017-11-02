import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.3
import QtQuick.Controls 2.2

Pane {
    id: notebookRoot
    // model interface:
    property var notebookModel: []

    Shortcut {
        sequence: StandardKey.Cancel
        context: Qt.ApplicationShortcut
        onActivated: {
            notebookRoot.visible = false
        }
    }

    SwipeView {
        id: view
        anchors.fill: parent

        // TODO: customize background as we prefer... :P
        background: Rectangle {
            color: "grey"
        }

        Repeater{
            model: notebookModel.pairs
            RowLayout{
                NotebookPage{
                    page: modelData.left
                }
                Image{
                    id: screw
                    width:44
                    Layout.fillHeight: true
                    clip: true
                    source: "qrc:/notebook_screw.jpg"
                    fillMode: Image.TileVertically
                    verticalAlignment: Image.AlignTop
                }
                NotebookPage{
                    page: modelData.right
                }
            }

        }
    }
    PageIndicator {
        count: view.count
        currentIndex: view.currentIndex
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
