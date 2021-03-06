#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "powerprotect.h"


int FileIO::header_id = -1;
int main(int argc, char *argv[])
{
    //**********************
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Powerprotect powerprotect;
    //test***************************
    engine.rootContext()->setContextProperty("pp", &powerprotect);
    engine.rootContext()->setContextObject(&powerprotect);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
