import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.shtxx 1.0

Page {
    id: page

    property string temperature : "?"
    property string humidity : "?"

    // To enable PullDownMenu, place our content in a SilicaFlickable
    SilicaFlickable {
        anchors.fill: parent

        // Tell SilicaFlickable the height of its content.
        contentHeight: column.height

        // Place our content in a Column.  The PageHeader is always placed at the top
        // of the page, followed by our content.
        Column {
            id: column

            width: page.width
            spacing: Theme.paddingLarge
            PageHeader {
                title: qsTr("SHTC1")
            }
            Row {
                Button {
                    text: "enable Vdd"
                    onClicked: shtxx.tohVddSet(true)
                }
                Button {
                    text: "disable Vdd"
                    onClicked: shtxx.tohVddSet(false)
                }
            }

            Button {
                text: qsTr("Refresh")
                onClicked: shtxx.update()
            }

            Label {
                text: qsTr("Status: ") + "?"
            }

            Label {
                text: qsTr("Temperature: ") + shtxx.sensorTemperature
            }
            Label {
                text: qsTr("Humidity: ") + shtxx.sensorHumidity
            }


        }
    }

    Shtxx
    {
        id: shtxx
    }
}


