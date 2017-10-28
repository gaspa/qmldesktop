import QtQuick 2.0
import QtQuick.Layouts 1.3

Item {
    // Model interface: //
    property string notebookTitle: "asdfasdfaf";
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
            height: notebookRoot.height
            source: "qrc:/notebook_screw.jpg"
            fillMode: Image.TileVertically
            verticalAlignment: Image.AlignTop
        }
        Rectangle
        {
            color: "white"
            Layout.fillWidth: true
            Layout.fillHeight: true
            Text
            {
                id: titleText
                color: "red"
                text: notebookTitle
                anchors.centerIn: parent.Center
            }
            Text
            {
                id: pagenuberText
                color: "black"
                text: notebookLength + " pages filled"
                anchors.top: titleText.bottom
            }
        }
    }
}
