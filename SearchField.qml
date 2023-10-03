import QtQuick
import QtQuick.Controls

Rectangle {
    id: root

    signal accepted(string value)

    border.color: searchInput.activeFocus ? "#77bdfb" : "#89929b"
    border.width: searchInput.activeFocus ? 1.5 : 1
    width: 500
    color: "transparent"
    radius: 6


    TextInput {
        id: searchInput

        anchors.fill: parent

        font.pixelSize: 14

        leftPadding: 30
        verticalAlignment: TextInput.AlignVCenter
        color: "white"

        Image {
            anchors {
              left: parent.left
              leftMargin: 5
              verticalCenter: parent.verticalCenter
            }

            width: 16
            height: 16

            mipmap: true
            source: "assets/search.ico"
        }

        onAccepted: {
            root.accepted(text)
        }
    }

}
