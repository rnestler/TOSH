import QtQuick 2.0
import Sailfish.Silica 1.0

CoverBackground {
    Column{
        anchors.centerIn: parent
        Label {
            id: temperature
            text: qsTr("Temperature: ")
        }
        Label {
            id: humidity
            text: qsTr("Humidity: ")
        }
    }

    CoverActionList {
        id: coverAction

        CoverAction {
            iconSource: "image://theme/icon-cover-refresh"
        }
    }
}


