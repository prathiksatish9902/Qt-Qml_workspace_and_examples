import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.mycompany.qmlcomponents 1.0

Rectangle {
    id: root
    width: 300
    height: 200
    anchors.centerIn: parent
    color: "white"
    border.color: "black"
    border.width: 3

    TextFileReader {
        id: model
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 10

        Button {
            text: "Read Text"
            onClicked: {
                model.readFile()
                _border.visible = true
                textOp.visible = false
            }
        }

        Button {
            text: "Write Text"
            onClicked: {
                model.writeFile()
                _border.visible = true
                textOp.visible = false
            }
        }
    }
}
