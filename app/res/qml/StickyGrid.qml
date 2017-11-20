import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Rectangle {
    property var blockModel: []

    id: noteThumbsRoot
    width: 400
    height: 200
    color: "lightgreen"

    Repeater{
        model: blockModel
        StickyNote{
            stickynoteModel: modelData
            isEditor: false

            x: 40 -noteThumbsRoot.width/2 + Math.random()*(noteThumbsRoot.width-40)
            y: 20 -noteThumbsRoot.height + Math.random()*(noteThumbsRoot.height-20)
            rotation: -90 + Math.random()*180
            scale: 0.2
            antialiasing: true
            onVisibleChanged: {
                console.log(x,y,width, height, rotation)
            }
        }
    }
}
