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

    Rectangle{
        anchors.fill: parent
        color: "lightgray"

        ColumnLayout{
            anchors.fill: parent

            RowLayout{
                height: 20
                Button
                {
                    id: newPageButton
                    text: "add new page..."
                    onClicked: {
                        notebookModel.addPage()
                    }
                }
            }

            SwipeView {
                id: view
                //anchors.fill: parent
                Layout.fillHeight: true
                Layout.fillWidth: true

                // TODO: customize background as we prefer... :P
                background: Rectangle {
                    color: "grey"
                }

                Repeater{
                    model: notebookModel.pairs
                    RowLayout{
                        spacing: 0
                        Layout.margins: 5

                        NotebookPage{
                            page: modelData.left
                            height: parent.height
                            width: (view.width - 44) / 2
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
                            height: parent.height
                            width: (view.width - 44) / 2
                        }
                    }

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
