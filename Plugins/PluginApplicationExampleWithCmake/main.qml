import QtQuick
import com.mycompany.qmlcomponents 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    MyItem {
        id: _myItem
    }
}
