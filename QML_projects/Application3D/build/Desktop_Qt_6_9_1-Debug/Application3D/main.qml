// import QtQuick
// import QtQuick.Window
// import QtQuick3D
// import QtQuick.Controls

// Window {
//     width: 800
//     height: 600
//     visible: true
//     title: "3D Rotating Rectangle with View3D"
//     color: "#2c3e50"

//     property int currentIndex: 0

//     // List of camera positions for each circle
//     ListModel {
//         id: cameraModel
//         ListElement { posX: 0; posY: 0; posZ: 0}
//         ListElement { posX: 0; posY: 0; posZ: 600 }      // Front
//         ListElement { posX: 0; posY: 0; posZ: -600 }     // Back
//         ListElement { posX: 0; posY: 600; posZ: 0 }      // Top
//         ListElement { posX: 0; posY: -600; posZ: 0 }     // Bottom
//         ListElement { posX: 600; posY: 0; posZ: 0 }      // Right
//         ListElement { posX: -600; posY: 0; posZ: 0 }     // Left
//         ListElement { posX: 400; posY: 400; posZ: 400 }  // Isometric
//     }

//     View3D {
//         id: view3D
//         anchors.fill: parent
//         anchors.leftMargin: 0

//         environment: SceneEnvironment {
//             clearColor: "#2c3e50"
//             backgroundMode: SceneEnvironment.Color
//         }

//         PerspectiveCamera {
//             id: camera
//             position: Qt.vector3d(0, 0, 600)
//             lookAtNode: rectangle3D
//         }

//         DirectionalLight {
//             eulerRotation.x: -30
//             eulerRotation.y: -30
//             brightness: 1.5
//         }

//         DirectionalLight {
//             eulerRotation.x: 30
//             eulerRotation.y: 150
//             brightness: 0.5
//         }

//         Model {
//             id: rectangle3D
//             source: "#Cube"
//             scale: Qt.vector3d(2, 2, 0.3)
//             materials: PrincipledMaterial {
//                 baseColor: "#3498db"
//                 metalness: 0.3
//                 roughness: 0.5
//             }
//         }
//     }

//     // Mouse rotation
//     MouseArea {
//         anchors.fill: view3D
//         property real lastX: 0
//         property real lastY: 0

//         onPressed: (mouse) => {
//             lastX = mouse.x
//             lastY = mouse.y
//         }

//         onPositionChanged: (mouse) => {
//             if (pressed) {
//                 var dx = mouse.x - lastX
//                 var dy = mouse.y - lastY

//                 rectangle3D.eulerRotation.y += dx * 0.5
//                 rectangle3D.eulerRotation.x -= dy * 0.5

//                 lastX = mouse.x
//                 lastY = mouse.y
//             }
//         }

//         onWheel: (wheel) => {
//             camera.position.z -= wheel.angleDelta.y * 0.5
//             camera.position.z = Math.max(200, Math.min(1000, camera.position.z))
//         }
//     }

//     // Bottom small circle indicators
//     Row {
//         id: indicatorRow
//         spacing: 12
//         anchors.bottom: parent.bottom
//         anchors.horizontalCenter: parent.horizontalCenter
//         anchors.bottomMargin: 20

//         Repeater {
//             model: cameraModel

//             Rectangle {
//                 width: index === currentIndex ? 14 : 10
//                 height: width
//                 radius: width / 2
//                 color: index === currentIndex ? "#ffffff" : "#7f8c8d"
//                 border.color: "#bdc3c7"
//                 border.width: 1

//                 MouseArea {
//                     anchors.fill: parent

//                     onClicked: {
//                         currentIndex = index
//                         cameraAnimation.to = Qt.vector3d(model.posX, model.posY, model.posZ)
//                         cameraAnimation.start()
//                     }
//                 }
//             }
//         }
//     }

//     Vector3dAnimation {
//         id: cameraAnimation
//         target: camera
//         property: "position"
//         duration: 400
//         easing.type: Easing.InOutQuad
//     }
// }























import QtQuick
import QtQuick.Window
import QtQuick3D
import QtQuick.Controls
import QtQuick.Layouts

Window {
    width: 1000
    height: 700
    visible: true
    title: "Plywood Cutting Simulation"
    color: "#2c3e50"

    // Current selected camera view index
    property int currentIndex: 1

    // Cut parameters (user input)
    property real cutWidth: 300
    property real cutHeight: 200
    property real cutDepth: 18     // thickness of cut piece
    property vector3d cutPosition: Qt.vector3d(-200, 100, 0)  // where the cut starts (adjustable later if needed)

    // Show/hide input dialog
    property bool showCutDialog: false

    ListModel {
        id: cameraModel
        ListElement { posX: 0;   posY: 0;   posZ: 0 }
        ListElement { posX: 0;   posY: 0;   posZ: 800 }
        ListElement { posX: 0;   posY: 0;   posZ: -800 }
        ListElement { posX: 0;   posY: 800; posZ: 0 }
        ListElement { posX: 0;   posY: -800; posZ: 0 }
        ListElement { posX: 800; posY: 0;   posZ: 0 }
        ListElement { posX: -800;posY: 0;   posZ: 0 }
        ListElement { posX: 600; posY: 600; posZ: 600 }
    }

    View3D {
        id: view3D
        anchors.fill: parent

        environment: SceneEnvironment {
            clearColor: "#2c3e50"
            backgroundMode: SceneEnvironment.Color
        }

        PerspectiveCamera {
            id: camera
            position: Qt.vector3d(0, 0, 800)
            lookAtNode: plywood
        }

        DirectionalLight { eulerRotation.x: -30; eulerRotation.y: -70; brightness: 2 }
        DirectionalLight { eulerRotation.x: 50;  eulerRotation.y: 20;  brightness: 0.8 }

        // Main plywood board (e.g. 2440 x 1220 x 18 mm standard sheet)
        Model {
            id: plywood
            source: "#Cube"
            scale: Qt.vector3d(12.2, 6.1, 0.09)  // 2440x1220x18 mm → scaled down
            materials: PrincipledMaterial {
                baseColor: "#d8a65a"
                metalness: 0
                roughness: 0.8
                normalMap: Texture { source: "qrc:/wood_normal.jpg" } // optional
            }
        }

        // CUT PREVIEW: Dotted wireframe box showing the piece to be cut
        Node {
            id: cutPreview
            visible: true  // always visible once defined
            opacity: 0.9

            // Scale and position based on user input
            position: cutPosition
            scale: Qt.vector3d(cutWidth/200, cutHeight/200, cutDepth/200)  // divide by 200 because base cube is 200 units

            // Wireframe cube with dashed lines using Line material
            Model {
                source: "#Cube"
                pickable: false
                materials: DefaultMaterial {
                    lighting: DefaultMaterial.NoLighting
                    cullMode: Material.NoCulling
                    lineWidth: 3
                    // Dashed effect via diffuse color animation or texture
                    diffuseColor: "#ff0000"
                    // We'll simulate dashed lines by using a custom shader or repeated geometry
                }
            }

            // Better dashed effect using multiple thin rotating lines (simple & reliable)
            Repeater3D {
                model: 12  // 12 edges of a cube
                delegate: Model {
                    source: "#Cylinder"
                    scale: Qt.vector3d(0.02, getEdgeLength(index), 0.02)
                    position: getEdgePosition(index)
                    eulerRotation: getEdgeRotation(index)
                    materials: DefaultMaterial {
                        lighting: DefaultMaterial.NoLighting
                        diffuseColor: "#ff0000"
                    }

                    // Dash pattern using opacity animation
                    SequentialAnimation on opacity {
                        loops: Animation.Infinite
                        PropertyAnimation { to: 0.2; duration: 300 }
                        PropertyAnimation { to: 1.0; duration: 300 }
                        PauseAnimation { duration: 200 }
                    }

                    // Helper functions to place each edge correctly
                    function getEdgeLength(idx) {
                        let edges = [
                            cutWidth, cutWidth, cutWidth, cutWidth,   // bottom
                            cutWidth, cutWidth, cutWidth, cutWidth,   // top
                            cutHeight, cutHeight, cutHeight, cutHeight // vertical
                        ];
                        return edges[idx] / 200 * 0.5;
                    }

                    function getEdgePosition(idx) {
                        let hw = cutWidth / 400, hh = cutHeight / 400, hd = cutDepth / 400;
                        let pos = [
                            Qt.vector3d(0, -hh, -hd), Qt.vector3d(0, -hh, hd), Qt.vector3d(-hw, -hh, 0), Qt.vector3d(hw, -hh, 0),
                            Qt.vector3d(0, hh, -hd),  Qt.vector3d(0, hh, hd),  Qt.vector3d(-hw, hh, 0),  Qt.vector3d(hw, hh, 0),
                            Qt.vector3d(-hw, 0, -hd), Qt.vector3d(hw, 0, -hd), Qt.vector3d(-hw, 0, hd), Qt.vector3d(hw, 0, hd)
                        ];
                        return pos[idx];
                    }

                    function getEdgeRotation(idx) {
                        let rots = [
                            Qt.vector3d(0,0,90), Qt.vector3d(0,0,90), Qt.vector3d(0,0,0), Qt.vector3d(0,0,0),
                            Qt.vector3d(0,0,90), Qt.vector3d(0,0,90), Qt.vector3d(0,0,0), Qt.vector3d(0,0,0),
                            Qt.vector3d(90,0,0), Qt.vector3d(90,0,0), Qt.vector3d(90,0,0), Qt.vector3d(90,0,0)
                        ];
                        return rots[idx];
                    }
                }
            }
        }
    }

    // Mouse rotation + zoom
    MouseArea {
        anchors.fill: view3D
        property real lastX: 0
        property real lastY: 0
        onPressed: (mouse) => { lastX = mouse.x; lastY = mouse.y }
        onPositionChanged: (mouse) => {
            if (pressed) {
                let dx = mouse.x - lastX
                let dy = mouse.y - lastY
                plywood.eulerRotation.y += dx * 0.5
                plywood.eulerRotation.x -= dy * 0.5
                cutPreview.eulerRotation.y += dx * 0.5
                cutPreview.eulerRotation.x -= dy * 0.5
                lastX = mouse.x; lastY = mouse.y
            }
        }
        onWheel: (wheel) => {
            camera.position.z -= wheel.angleDelta.y * 0.5
            camera.position.z = Math.max(300, Math.min(2000, camera.position.z))
        }
    }

    // Camera view indicators (bottom)
    Row {
        id: indicatorRow
        spacing: 12
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20
        Repeater {
            model: cameraModel
            Rectangle {
                width: index === currentIndex ? 14 : 10
                height: width
                radius: width / 2
                color: index === currentIndex ? "#ffffff" : "#7f8c8d"
                border.color: "#bdc3c7"
                border.width: 1
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        currentIndex = index
                        cameraAnimation.to = Qt.vector3d(model.posX, model.posY, model.posZ)
                        cameraAnimation.start()
                    }
                }
            }
        }
    }

    Vector3dAnimation { id: cameraAnimation; target: camera; property: "position"; duration: 600; easing.type: Easing.InOutQuad }

    // === UI CONTROLS ===
    ColumnLayout {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 20
        spacing: 15

        Button {
            text: "New Cut Piece"
            font.pixelSize: 16
            onClicked: showCutDialog = true
        }

        // Optional: Show current cut dimensions
        Column {
            visible: true
            Text { text: "Current Cut:"; color: "white"; font.bold: true }
            Text { text: `${cutWidth} × ${cutHeight} × ${cutDepth} mm`; color: "#a8dadc" }
        }
    }

    // === INPUT DIALOG ===
    Rectangle {
        visible: showCutDialog
        anchors.centerIn: parent
        width: 400
        height: 380
        color: "#34495e"
        radius: 12
        border.color: "#1abc9c"
        border.width: 3

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 20

            Text {
                text: "Define Cut Piece"
                color: "white"
                font.pixelSize: 22
                Layout.alignment: Qt.AlignHCenter
            }

            GridLayout {
                columns: 2
                Text { text: "Width (mm):"; color: "white" }
                TextField { text: cutWidth; onTextChanged: cutWidth = parseFloat(text) || 300 }

                Text { text: "Height (mm):"; color: "white" }
                TextField { text: cutHeight; onTextChanged: cutHeight = parseFloat(text) || 200 }

                Text { text: "Thickness (mm):"; color: "white" }
                TextField { text: cutDepth; onTextChanged: cutDepth = parseFloat(text) || 18 }
            }

            RowLayout {
                spacing: 20
                Layout.alignment: Qt.AlignHCenter

                Button {
                    text: "Cancel"
                    onClicked: showCutDialog = false
                }
                Button {
                    text: "Apply Cut Preview"
                    highlighted: true
                    onClicked: {
                        showCutDialog = false
                        // You can later add logic to validate if it fits inside the sheet
                    }
                }
            }
        }
    }
}
