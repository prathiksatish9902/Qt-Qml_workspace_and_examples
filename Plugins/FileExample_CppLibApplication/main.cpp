// #include <QGuiApplication>
// #include <QQmlApplicationEngine>
// // #include <QPluginLoader>
// #include <QLibrary>
// // #include "txtfilereader.h"
// // #include "csvfilereader.h"
// // #include "fileexample_cpplibplugin.h"

// typedef TxtFileReader* (*CreateTxtReaderFunc)();


// int main(int argc, char *argv[])
// {
// #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
//     QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
// #endif
//     QGuiApplication app(argc, argv);

//     // QPluginLoader pluginLoader("/home/prathik/QT_WORKSPACE/Plugins/fileExamplePlugin/build/Desktop_Qt_5_15_2_GCC_64bit-Debug/libfileExamplePlugin.so");
//     // bool success = pluginLoader.load();
//     // qDebug() << pluginLoader.errorString();


//     // if(success){
//     //     qDebug()<<"true";
//     // }
//     // else{
//     //     qDebug()<<"false";
//     // }



//     QLibrary lib("/home/prathik/QT_WORKSPACE/Plugins/FileExample_CppLibApplication/bin/libFileExample_CppLibPlugin.so");
//     // lib.load();

//     if (!lib.load()) {
//         qDebug() << "Error loading library:" << lib.errorString();
//     } else {
//         qDebug() << "Library loaded successfully!";
//     }

//     CreateTxtReaderFunc createReader = (CreateTxtReaderFunc)lib.resolve("createTxtReader");
//     if (!createReader) {
//         qDebug() << "Function not found:" << lib.errorString();
//         return -1;
//     }

//     TxtFileReader* reader = createReader();
//     reader->readFile();
//     reader->writeFile();

//     QQmlApplicationEngine engine;
//     const QUrl url(QStringLiteral("qrc:/main.qml"));
//     QObject::connect(
//         &engine,
//         &QQmlApplicationEngine::objectCreated,
//         &app,
//         [url](QObject *obj, const QUrl &objUrl) {
//             if (!obj && url == objUrl)
//                 QCoreApplication::exit(-1);
//         },
//         Qt::QueuedConnection);
//     engine.load(url);

//     return app.exec();
// }



#include <QCoreApplication>
#include <QLibrary>
#include <QDebug>

// Function pointer typedefs
typedef void* (*CreateReaderFunc)();
typedef void (*ReaderActionFunc)(void*);
typedef void (*DeleteReaderFunc)(void*);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // Load the plugin library
    QString libraryPath = "/home/prathik/QT_WORKSPACE/Plugins/FileExample_CppLibApplication/bin/libFileExample_CppLibPlugin.so";
    QLibrary library(libraryPath);

    if (library.load()) {
        qDebug() << "Library loaded successfully";

        // Resolve functions
        CreateReaderFunc createTxtReader = (CreateReaderFunc)library.resolve("createTxtReader");
        ReaderActionFunc txtReaderRead = (ReaderActionFunc)library.resolve("txtReaderRead");
        ReaderActionFunc txtReaderWrite = (ReaderActionFunc)library.resolve("txtReaderWrite");
        DeleteReaderFunc deleteTxtReader = (DeleteReaderFunc)library.resolve("deleteTxtReader");

        if (createTxtReader && txtReaderRead && txtReaderWrite && deleteTxtReader) {
            // Create and use the reader
            void* reader = createTxtReader();

            if (reader) {
                txtReaderRead(reader);
                txtReaderWrite(reader);
                deleteTxtReader(reader);
            }
        } else {
            qDebug() << "Failed to resolve functions";
        }
    } else {
        qDebug() << "Failed to load library:" << library.errorString();
    }

    return 0;
}
