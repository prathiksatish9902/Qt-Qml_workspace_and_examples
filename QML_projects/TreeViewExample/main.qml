// import QtQuick 2.12
// import QtQuick.Window 2.12
// import QtQuick.Controls 1.4
// import QtQuick.Controls 2.12 as Controls2
// import QtQuick.Layouts 1.12

// Window {
//     width: 900
//     height: 600
//     visible: true
//     title: qsTr("Company & Employee TreeView")

//     property var selectedCompanyData: null
//     property int expandedRows: 0
//     property int rowHeight: 80
//     property int selectedRowIndex: -1
//     property int currentSubLevel: 0  // 0=all visible, 1=only ID, 2=ID+Year, 3=ID+Year+Location, etc.

//     ColumnLayout {
//         anchors.fill: parent
//         anchors.margins: 10
//         spacing: 10

//         TreeView {
//             id: treeView
//             Layout.fillHeight: true
//             Layout.fillWidth: true
//             model: treeModel
//             alternatingRowColors: true
//             selectionMode: SelectionMode.SingleSelection
//             headerVisible: true
//             sortIndicatorVisible:false

//             rowDelegate: Rectangle {
//                 height: rowHeight
//                 color: model.selected ? "lightsteelblue" : "#E3F2FD"
//                 border.color:  model.selected ? "#2196F3" : "#4682B4"
//                 border.width:  model.selected ? 2 : 0
//             }

//             TableViewColumn {
//                 title: "Company"
//                 role: "display"
//                 width: 120

//                 delegate: Rectangle {
//                     width: 120
//                     height: 50
//                     anchors.verticalCenter: parent.verticalCenter
//                     color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                     border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                     border.width: model.selected ? 2 : 1

//                     Image {
//                         anchors.centerIn: parent
//                         width: 40
//                         height: 40
//                         source: "qrc:/icons8-select-48.png"
//                         fillMode: Image.PreserveAspectFit
//                     }

//                     MouseArea {
//                         anchors.fill: parent
//                         cursorShape: Qt.PointingHandCursor
//                         onClicked: {
//                             console.log("Clicked company row:", styleData.row, "index valid:", styleData.index.valid)
//                             console.log("Model index row:", styleData.index.row, "column:", styleData.index.column)
//                             if (styleData.index.valid) {
//                                 treeModel.selectedCompany(styleData.index.row)
//                             }
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "ID"
//                 role: "display"
//                 width: 100

//                 delegate: Controls2.TextField {
//                     anchors.fill: parent
//                     anchors.margins: 2
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter ID"
//                     selectByMouse: true

//                     onModelValueChanged: {
//                         if (!activeFocus) {
//                             text = modelValue
//                         }
//                     }

//                     background: Rectangle {
//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     onEditingFinished: {
//                         console.log("ID updated:", text)
//                         if (treeModel.updateCompanyField(styleData.index, 1, text)) {
//                             console.log("Successfully updated ID to:", text)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "Year"
//                 role: "display"
//                 width: 100

//                 delegate: Controls2.TextField {
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter Year"
//                     font.pixelSize: styleData.depth === 0 ? 14 : 11
//                     font.bold: styleData.depth === 0
//                     color: styleData.depth === 0 ? "#1565c0" : "#333"
                    
//                     // Update text when model data changes
//                     onModelValueChanged: {
//                         if (!activeFocus) { // Only update if not currently being edited
//                             text = modelValue
//                         }
//                     }
                    
//                     background: Rectangle {

//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         radius: 8
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     selectByMouse: true

//                     onEditingFinished: {
//                         console.log("Year updated for row", styleData.row, ":", text)
//                         if (treeModel.updateCompanyField(styleData.index, 2, text)) {
//                             console.log("Successfully updated Year to:", text)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "Location"
//                 role: "display"
//                 width: 150

//                 delegate: Controls2.TextField {
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter Location"
//                     font.pixelSize: styleData.depth === 0 ? 14 : 11
//                     font.bold: styleData.depth === 0
//                     color: styleData.depth === 0 ? "#1565c0" : "#333"
                    
//                     // Update text when model data changes
//                     onModelValueChanged: {
//                         if (!activeFocus) { // Only update if not currently being edited
//                             text = modelValue
//                         }
//                     }
                    
//                     background: Rectangle {

//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         radius: 8
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     selectByMouse: true

//                     onEditingFinished: {
//                         console.log("Location updated for row", styleData.row, ":", text)
//                         if (treeModel.updateCompanyField(styleData.index, 3, text)) {
//                             console.log("Successfully updated Location to:", text)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "Industry"
//                 role: "display"
//                 width: 150

//                 delegate: Controls2.TextField {
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter Industry"
//                     font.pixelSize: styleData.depth === 0 ? 14 : 11
//                     font.bold: styleData.depth === 0
//                     color: styleData.depth === 0 ? "#1565c0" : "#333"
                    
//                     // Update text when model data changes
//                     onModelValueChanged: {
//                         if (!activeFocus) { // Only update if not currently being edited
//                             text = modelValue
//                         }
//                     }
                    
//                     background: Rectangle {
//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     selectByMouse: true

//                     onEditingFinished: {
//                         console.log("Industry updated for row", styleData.row, ":", text)
//                         if (treeModel.updateCompanyField(styleData.index, 4, text)) {
//                             console.log("Successfully updated Industry to:", text)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "CEO"
//                 role: "display"
//                 width: 150

//                 delegate: Controls2.TextField {
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter CEO"
//                     font.pixelSize: styleData.depth === 0 ? 14 : 11
//                     font.bold: styleData.depth === 0
//                     color: styleData.depth === 0 ? "#1565c0" : "#333"
                    
//                     // Update text when model data changes
//                     onModelValueChanged: {
//                         if (!activeFocus) { // Only update if not currently being edited
//                             text = modelValue
//                         }
//                     }
                    
//                     background: Rectangle {
//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     selectByMouse: true

//                     onEditingFinished: {
//                         console.log("CEO updated for row", styleData.row, ":", text)
//                         if (treeModel.updateCompanyField(styleData.index, 5, text)) {
//                             console.log("Successfully updated CEO to:", text)
//                         }
//                     }
//                 }
//             }
//             TableViewColumn {
//                 title: "Status"
//                 role: "display"
//                 width: 100
//                 visible: currentSubLevel === 0 || currentSubLevel >= 6

//                 delegate: Controls2.TextField {
//                     property string modelValue: styleData.value || ""
//                     text: modelValue
//                     placeholderText: "Enter Status"
//                     font.pixelSize: styleData.depth === 0 ? 14 : 11
//                     font.bold: styleData.depth === 0
//                     color: styleData.depth === 0 ? "#1565c0" : "#333"

//                     // Update text when model data changes
//                     onModelValueChanged: {
//                         if (!activeFocus) { // Only update if not currently being edited
//                             text = modelValue
//                         }
//                     }

//                     background: Rectangle {
//                         color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                         border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                         border.width: model.selected ? 2 : 1
//                     }
//                     selectByMouse: true

//                     onEditingFinished: {
//                         console.log("Status updated for row", styleData.row, ":", text)
//                         if (treeModel.updateCompanyField(styleData.index, 6, text)) {
//                             console.log("Successfully updated Status to:", text)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "Action"
//                 role: "display"
//                 width: 80

//                 delegate: Rectangle {
//                     width: 80
//                     height: 50
//                     anchors.verticalCenter: parent.verticalCenter
//                     color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                     border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                     border.width: model.selected ? 2 : 1

//                     Image {
//                         anchors.centerIn: parent
//                         width: 30
//                         height: 30
//                         source: "qrc:/icons8-select-48.png"
//                         fillMode: Image.PreserveAspectFit
//                     }

//                     MouseArea {
//                         anchors.fill: parent
//                         cursorShape: Qt.PointingHandCursor
//                         onClicked: {
//                             console.log("Action clicked for row:", styleData.row)
//                         }
//                     }
//                 }
//             }

//             TableViewColumn {
//                 title: "Rating"
//                 role: "display"
//                 width: 100

//                 delegate: Rectangle {
//                     width: 100
//                     height: 50
//                     anchors.verticalCenter: parent.verticalCenter
//                     color: model.selected ? "#E1F5FE" : "#F0F8FF"
//                     border.color: model.selected ?"#4682B4" :  "#E0E0E0"
//                     border.width: model.selected ? 2 : 1

//                     Image {
//                         anchors.centerIn: parent
//                         width: 30
//                         height: 30
//                         source: "qrc:/icons8-select-48.png"
//                         fillMode: Image.PreserveAspectFit
//                     }

//                     MouseArea {
//                         anchors.fill: parent
//                         cursorShape: Qt.PointingHandCursor
//                         onClicked: {
//                             console.log("Rating clicked for row:", styleData.row)
//                             treeView.selection.select(styleData.index)
//                         }
//                     }
//                 }
//             }
//         }

//         Rectangle {
//             id: footer
//             Layout.fillWidth: true
//             height: 50
//             radius: 6
//             color: "#fafafa"
//             border.color: "#d0d0d0"

//             RowLayout {
//                 anchors.fill: parent
//                 anchors.margins: 8
//                 spacing: 10

//                 Button {
//                     text: "Add"
//                     Layout.fillHeight: true
//                     Layout.fillWidth: true
//                     onClicked: {
//                         console.log("Add template button clicked")
//                         treeModel.addEmptyTemplate()
//                     }
//                 }

//                 Button {
//                     text: "Add Sub 1"
//                     Layout.fillHeight: true
//                     Layout.fillWidth: true
//                     onClicked: {
//                         console.log("Add template button clicked")
//                         treeModel.addEmptyTemplate()
//                     }
//                 }

//                 Button {
//                     text: "Add Sub 2"
//                     Layout.fillHeight: true
//                     Layout.fillWidth: true
//                     onClicked: {
//                         console.log("Add template button clicked")
//                         treeModel.addEmptyTemplate()
//                     }
//                 }

//                 Button {
//                     text: "Add Sub 3"
//                     Layout.fillHeight: true
//                     Layout.fillWidth: true
//                     onClicked: {
//                         console.log("Add template button clicked")
//                         treeModel.addEmptyTemplate()
//                     }
//                 }

//                 Button {
//                     text: "Delete"
//                     Layout.fillHeight: true
//                     Layout.fillWidth: true
//                     onClicked: {
//                         console.log("Delete button clicked")
//                     }
//                 }
//             }
//         }
//     }


// }











// ```qml
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls 2.12 as Controls2
import QtQuick.Layouts 1.12

Window {
    width: 900
    height: 600
    visible: true
    title: qsTr("Company & Employee TreeView")

    property var selectedCompanyData: null
    property int expandedRows: 0
    property int rowHeight: 80
    property int selectedRowIndex: -1
    property int currentSubLevel: 0  // 0=all visible, 1=only ID, 2=ID+Year, 3=ID+Year+Location, etc.

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        spacing: 10

        TreeView {
            id: treeView
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: treeModel
            alternatingRowColors: true
            selectionMode: SelectionMode.SingleSelection
            headerVisible: true
            sortIndicatorVisible:false

            rowDelegate: Rectangle {
                height: rowHeight
                color: model.selected ? "lightsteelblue" : "#E3F2FD"
                border.color:  model.selected ? "#2196F3" : "#4682B4"
                border.width:  model.selected ? 2 : 0
            }

            TableViewColumn {
                title: "Company"
                role: "display"
                width: 120

                delegate: Rectangle {
                    width: 120
                    height: 50
                    anchors.verticalCenter: parent.verticalCenter
                    color: model.selected ? "#E1F5FE" : "#F0F8FF"
                    border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                    border.width: model.selected ? 2 : 1

                    Image {
                        anchors.centerIn: parent
                        width: 40
                        height: 40
                        source: "qrc:/icons8-select-48.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            if (styleData.index.valid) {
                                // Tell C++ model to toggle selection for this top-level row
                                treeModel.selectedCompany(styleData.index.row)
                            }
                        }
                    }
                }
            }

            TableViewColumn {
                title: "ID"
                role: "display"
                width: 100

                delegate: Controls2.TextField {
                    anchors.fill: parent
                    anchors.margins: 2
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter ID"
                    selectByMouse: true

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 1, text)) {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "Year"
                role: "display"
                width: 100

                delegate: Controls2.TextField {
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter Year"
                    font.pixelSize: styleData.depth === 0 ? 14 : 11
                    font.bold: styleData.depth === 0
                    color: styleData.depth === 0 ? "#1565c0" : "#333"

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        radius: 8
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    selectByMouse: true

                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 2, text)) {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "Location"
                role: "display"
                width: 150

                delegate: Controls2.TextField {
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter Location"
                    font.pixelSize: styleData.depth === 0 ? 14 : 11
                    font.bold: styleData.depth === 0
                    color: styleData.depth === 0 ? "#1565c0" : "#333"

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        radius: 8
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    selectByMouse: true

                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 3, text)) {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "Industry"
                role: "display"
                width: 150

                delegate: Controls2.TextField {
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter Industry"
                    font.pixelSize: styleData.depth === 0 ? 14 : 11
                    font.bold: styleData.depth === 0
                    color: styleData.depth === 0 ? "#1565c0" : "#333"

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    selectByMouse: true

                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 4, text)) {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "CEO"
                role: "display"
                width: 150

                delegate: Controls2.TextField {
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter CEO"
                    font.pixelSize: styleData.depth === 0 ? 14 : 11
                    font.bold: styleData.depth === 0
                    color: styleData.depth === 0 ? "#1565c0" : "#333"

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    selectByMouse: true

                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 5, text)) {
                        }
                    }
                }
            }
            TableViewColumn {
                title: "Status"
                role: "display"
                width: 100
                visible: currentSubLevel === 0 || currentSubLevel >= 6

                delegate: Controls2.TextField {
                    property string modelValue: styleData.value || ""
                    text: modelValue
                    placeholderText: "Enter Status"
                    font.pixelSize: styleData.depth === 0 ? 14 : 11
                    font.bold: styleData.depth === 0
                    color: styleData.depth === 0 ? "#1565c0" : "#333"

                    onModelValueChanged: {
                        if (!activeFocus) {
                            text = modelValue
                        }
                    }

                    background: Rectangle {
                        color: model.selected ? "#E1F5FE" : "#F0F8FF"
                        border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                        border.width: model.selected ? 2 : 1
                    }
                    selectByMouse: true

                    onEditingFinished: {
                        if (treeModel.updateCompanyField(styleData.index, 6, text)) {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "Action"
                role: "display"
                width: 80

                delegate: Rectangle {
                    width: 80
                    height: 50
                    anchors.verticalCenter: parent.verticalCenter
                    color: model.selected ? "#E1F5FE" : "#F0F8FF"
                    border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                    border.width: model.selected ? 2 : 1

                    Image {
                        anchors.centerIn: parent
                        width: 30
                        height: 30
                        source: "qrc:/icons8-select-48.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                        }
                    }
                }
            }

            TableViewColumn {
                title: "Rating"
                role: "display"
                width: 100

                delegate: Rectangle {
                    width: 100
                    height: 50
                    anchors.verticalCenter: parent.verticalCenter
                    color: model.selected ? "#E1F5FE" : "#F0F8FF"
                    border.color: model.selected ?"#4682B4" :  "#E0E0E0"
                    border.width: model.selected ? 2 : 1

                    Image {
                        anchors.centerIn: parent
                        width: 30
                        height: 30
                        source: "qrc:/icons8-select-48.png"
                        fillMode: Image.PreserveAspectFit
                    }

                    MouseArea {
                        anchors.fill: parent
                        cursorShape: Qt.PointingHandCursor
                        onClicked: {
                            treeView.selection.select(styleData.index)
                        }
                    }
                }
            }
        }

        Rectangle {
            id: footer
            Layout.fillWidth: true
            height: 50
            radius: 6
            color: "#fafafa"
            border.color: "#d0d0d0"

            RowLayout {
                anchors.fill: parent
                anchors.margins: 8
                spacing: 10

                Button {
                    text: "Add"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    onClicked: {
                        // Add a child under the selected company, or a top-level template if none selected
                        treeModel.addChildForSelected()
                    }
                }

                Button {
                    text: "Add Sub 1"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    onClicked: {
                        // Copy first column (ID) into the child ID field
                        treeModel.addSub1ForSelected()
                    }
                }

                Button {
                    text: "Add Sub 2"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    onClicked: {
                        // Copy ID + Year
                        treeModel.addSub2ForSelected()
                    }
                }

                Button {
                    text: "Add Sub 3"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    onClicked: {
                        // Copy ID + Year + Location
                        treeModel.addSub3ForSelected()
                    }
                }

                Button {
                    text: "Delete"
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    onClicked: {
                        console.log("Delete button clicked")
                    }
                }
            }
        }
    }
}
