import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.12
import Qt.labs.platform 1.1


Window {
    visible: true
//    width: 640
//    height: 480

    minimumWidth: 600
    minimumHeight: 300
    maximumWidth: 600
    maximumHeight: 300

//    color: '#353535'

    title: qsTr("QML Preview 1.0")

    Column {
        anchors.centerIn: parent
        spacing: 40

        Rectangle {
               id: inputBox
               width: 390
               height: 40
               color: "#F3F6FA"
               clip: true
               border.width: 1
               border.color: "#DFE0E4"
               radius: 5

               TextInput {
                   id: inputBoxInput
                   text:folderDialog.file
                   anchors.rightMargin: -41
                   color: "#707070"
                   font.pixelSize: 16
                   activeFocusOnTab: true
                   selectByMouse: true //是否可以选择文本
                   selectedTextColor: "white" //设置选择文本的字体颜色
                   selectionColor: "#4A6DBC" //设置选择框的颜色
                   verticalAlignment: TextInput.AlignVCenter
                   horizontalAlignment: TextInput.AlignLeft
                   anchors.fill: parent
                   leftPadding: 3
                   rightPadding: 3

                   }
               }

        Row {
            spacing: 150

                Button{

                    height: 40
                    width: 120

                    text: qsTr("选择文件")
                    font.family: 'Microsoft YaHei'
                    font.pointSize: 12
                    font.letterSpacing: 2

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            folderDialog.open()
                        }
                    }
                }


                Button {
                    height: 40
                    width: 120
                    objectName: "btn1"
                    signal setdir

                    text: qsTr("预览")
                    font.family: 'Microsoft YaHei'
                    font.pointSize: 12
                    font.letterSpacing: 2

                    onClicked: {
                        console.log('click')
                        Myconfig.setPreviewDIR(folderDialog.file.toString())
                        Myconfig.setPreviewFolder(folderDialog.folder.toString())
                        setdir()
                    }
                }

            }   //Row

    }   //Column




    FileDialog {
        id: folderDialog
        folder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0] //默认打开Pictures文件夹
        title: "选择文件"
        nameFilters: ["QML文件 (*.qml)"]
    }    //FileDialog



}   //window



