import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.mycompany.qmlcomponents 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: "Hello World"

    TextOperation {
        id: textOp
        visible: false
    }

    CsvOperation {
        id: csvOp
        visible: false
    }

    Rectangle {
        id: _border
        width: 300
        height: 200
        anchors.centerIn: parent
        color: "white"
        border.color: "black"
        border.width: 3

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 10

            Button {
                text: "Text"
                onClicked: {
                    textOp.visible = true
                    csvOp.visible = false
                    _border.visible = false
                }
            }

            Button {
                text: "Csv"
                onClicked: {
                    csvOp.visible = true
                    textOp.visible = false
                    _border.visible = false

                }
            }
        }
    }
}
