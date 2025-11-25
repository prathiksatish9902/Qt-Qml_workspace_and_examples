import QtQuick 2.15
import QtQuick.Controls 2.15
import com.mycompany.qmlcomponents 1.0
Item {
MyItem {
    id: _myitem
}
Button {
    text: "click me"
    onClicked: _myitem.setName("Prathik")
}
}
