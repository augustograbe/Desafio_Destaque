import QtQuick
import QtQuick.Controls
import QtQuick.Window

import com.company.RepSearch

Window {
    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("Busca de repositórios do GitHub")
    color: "#21262d"

    Rectangle {
        id: topbar

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: 50
        color: "#161b22"

        Image {
            anchors {
              left: parent.left
              leftMargin: 10
              verticalCenter: parent.verticalCenter
            }

            width: 30
            height: 30

            mipmap: true
            source: "assets/github-logo.png"
        }

        SearchField {
            anchors {
                left: parent.left

                verticalCenter: parent.verticalCenter
                margins: 10
                leftMargin: 60
            }

            height: 30

            onAccepted: value => {
                                RepSearch.searchRep(value)
                                topbar.forceActiveFocus()
                              }
        }
    }
    SearchPanel {
        id: searchPanel
        color: "#21262d"
        border.color: "#89929b"
        border.width: 1

        anchors {
          left: parent.left
          right: parent.right
          top: topbar.bottom
          rightMargin: -border.width
          leftMargin: -border.width
        }

        height: parent.height - topbar.height
    }
}
