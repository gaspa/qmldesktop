import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    property var blockModel: []

    RowLayout{
        Layout.fillWidth: true

        Button {
            id: addNote
            text: qsTr("+")
            onClicked: {
                blockModel.append({'bodyColor': 'yellow', 'title': 'new note', 'body': '...'});
                console.log("asdfafs", blockModel)
            }
        }
    }

    GridView {
        id: gridView
        Layout.fillHeight: true
        Layout.fillWidth: true

        cellHeight: 110
        cellWidth:110

        model: blockModel
        delegate: StickyNote{

            bodyColor: model.bodyColor
            title: model.title
            body: model.body
        }
    }
}
