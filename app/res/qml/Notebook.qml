import QtQuick 2.0
import QtQuick.Controls 2.2

Pane {
    id: notebookRoot
    // model interface:
    property var notebookModel: []
    SwipeView {
        id: view
        anchors.fill: parent

        // TODO: customize background as we prefer... :P
        background: Rectangle {
            color: "grey"
        }

        Repeater{
            model: notebookModel.pages
            Rectangle{
                Text{
                    text: modelData.title + " - " + modelData.pagenumber;
                    anchors.centerIn: parent
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
