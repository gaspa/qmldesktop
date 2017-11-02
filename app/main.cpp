#include <QDebug>
#include <QFont>
#include <QFontDatabase>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "models/desktop.h"

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // TODO: do in qml?
    //    QFontDatabase fontdb;
    //    qDebug() << fontdb.families();
    app.setFont(QFont("Ubuntu Light", 10));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("desktopModel", new Desktop());
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
