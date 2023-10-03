import QtQuick
import com.company.RepSearch

Rectangle {
  id: root
  color: red

  ListView {
    id: listView

    anchors {
      fill: parent
      margins: 20
    }

    spacing: 10
    clip: true
    model: RepSearch
    //visible: !RepSearch.isSearching

    delegate: Rectangle {
      id: delegate

      required property string repName
      required property string repAuthor
      required property string repDescription
      required property string repLanguage
      required property int repStars
      required property int repForks
      required property string repDate

      width: listView.width
      height: 100

      radius: 6
      color: "transparent"
      border.color: "#89929b"
      border.width: 1

      Column {
        anchors {
            left: parent.left
            top: parent.top

            margins: 5
        }

        spacing: 10

        Text {
            id: repNameblock
            width: parent.width
            anchors {
                left: parent.left
                top: parent.top
                margins: 5
            }

            text: delegate.repAuthor + "/" + delegate.repName
            color: "#77bdfb"

            font {
                pixelSize: 14
                bold: true
            }
        }

        Text {
            width: parent.width
            height: 60
            anchors {
                left: parent.left
                top: repNameblock.top
                margins: 5
                topMargin: 25
            }

            text: delegate.repDescription
            color: "white"
            wrapMode: Text.Wrap

            font {
                pixelSize: 12
            }
        }

        Text {
          width: parent.width

          text: delegate.repAuthor
          color: "gray"

          fontSizeMode: Text.Fit
          minimumPixelSize: 8
          elide: Text.ElideRight

          font {
            pixelSize: 12
          }
        }

        Text {
          width: parent.width

          text: delegate.repLanguage
          color: "gray"

          fontSizeMode: Text.Fit
          minimumPixelSize: 8
          elide: Text.ElideRight

          font {
            pixelSize: 12
          }
        }
      }

      MouseArea {
        anchors.fill: parent

        onClicked: {

        }
      }
    }
  }

  Text {
    anchors.centerIn: parent

    color: "gray"
    visible: RepSearch.isSearching || listView.count === 0
    text: if (RepSearch.isSearching) {
            return "Searching..."
          } else if (listView.count === 0) {
            return "No results"
          } else {
            return ""
          }

    font {
      pixelSize: 24
      bold: true
    }
  }

  Behavior on y {
    PropertyAnimation {
      easing.type: Easing.InOutQuad
      duration: 200
    }
  }
}
