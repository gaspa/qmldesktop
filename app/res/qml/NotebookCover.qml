import QtQuick 2.0
import QtQuick.Layouts 1.3

Rectangle {
    // Model interface: //
    property string notebookTitle: "Memories";
    property int notebookLength: 0;

    // end model interface //

    id: notebookRoot
    RowLayout {
        anchors.fill: parent
        spacing: 0
        Image
        {
            id: screw
            width:44
            Layout.fillHeight: true
            clip: true
            source: "qrc:/notebook_screw.jpg"
            fillMode: Image.TileVertically
            verticalAlignment: Image.AlignTop
        }
        Rectangle
        {
            color: "white"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Image{
                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
                horizontalAlignment: Image.AlignHCenter
                verticalAlignment: Image.AlignVCenter
                source: "qrc:/brina.jpg"
            }

            Text
            {
                id: titleText
                color: "red"
                text: notebookTitle
                font.bold: true
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }
            Text
            {
                id: pagenuberText
                color: "black"
                text: notebookLength + " pages filled"
                font.pointSize: 8
                anchors.top: titleText.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
