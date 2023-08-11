#include <QGuiApplication>
#include <QQuickView>
#include <QUrl>
#include <QDir>
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QObject>
#include <QQmlContext>
#include <QMetaObject>

#include "myconfig.h"
#include "filesystemwatcher.h"


////预览界面文件路径

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);



    //注册到qml
    Myconfig myconfig("C:/", "C:/");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    //注册上下文
    auto context = engine.rootContext();
    context -> setContextProperty("Myconfig", &myconfig);


    //获取qml根对象
    auto root = engine.rootObjects();
    //根据objectname查找对象
    auto buttonqml = root.first() -> findChild<QObject*>("btn1");

    QObject::connect(buttonqml, SIGNAL(setdir()), &myconfig, SLOT(setPreview()));



    //加载设置界面
    QQuickView _preview;

//    QDir DIRECTORY_set("C:\\Users\\XXX\\Desktop\\QMLpreview\\QMLpreview");
//    QUrl SOURCE_URL_set = QUrl::fromLocalFile(DIRECTORY_set.filePath("page1.qml"));


    //获取加载页面指针
    myconfig.setPreviewPtr(&_preview);

//    FileSystemWatcher::addWatchPath("C:\\Users\\XXX\\Desktop\\QMLpreview\\QMLpreview\\page1.qml");

    return app.exec();
}
