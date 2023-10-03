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
        height: 105

        radius: 6
        color: "transparent"
        border.color: "#89929b"
        border.width: 1

        Text {
            id: repNameblock
            width: parent.width
            height:40
            anchors {
                left: parent.left
                top: parent.top
                margins: 10
            }

            text: delegate.repAuthor + "/" + delegate.repName
            color: "#77bdfb"

            font {
                pixelSize: 14
                bold: true
            }
        }

        Text {
            id: repDescriptionblock
            width: parent.width - 10
            height: 60
            anchors {
                left: parent.left
                top: repNameblock.top
                margins: 10
                topMargin: 25
            }

            text: delegate.repDescription
            color: "white"
            wrapMode: Text.Wrap
            fontSizeMode: Text.Fit
            elide: Text.ElideRight

            font {
                pixelSize: 12
            }
        }

        Text {
            id: repLanguageblock
            width:60
            anchors {
                left: parent.left
                top: repDescriptionblock.top
                margins: 10
                topMargin: 45
            }

            text: delegate.repLanguage
            color: "gray"

            font {
                pixelSize: 12
            }
        }

        Text {
            id: repDateblock

            anchors {
                right: parent.right
                top: repDescriptionblock.top
                margins: 10
                topMargin: 45
            }

            text: delegate.repDate
            color: "gray"

            font {
                pixelSize: 12
            }
        }

        Rectangle {
            anchors {
                right: parent.right
                top: parent.top
                margins: 10
            }

            Row {

                Text {
                    id: repStarsblock
                    //width: 50
                    anchors {
                        right: parent.right
                        top: parent.top
                    }

                    text: delegate.repStars
                    color: "gray"

                    font {
                        pixelSize: 12
                    }
                }
                Image {
                    anchors {
                      right: repStarsblock.left
                      top: parent.top
                      rightMargin: 5
                      topMargin: 2
                    }

                    width: 12
                    height: 12

                    mipmap: true
                    source: "assets/star.ico"
                }

                Text {
                    id: repForksblock
                    anchors {
                        right: parent.right
                        top: parent.top
                        rightMargin: 80
                    }

                    text: delegate.repForks
                    color: "gray"

                    font {
                        pixelSize: 12
                    }
                }
                Image {
                    anchors {
                      right: repForksblock.left
                      top: parent.top
                      rightMargin: 5
                      topMargin: 2
                    }

                    width: 12
                    height: 12

                    mipmap: true
                    source: "assets/fork.ico"
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
