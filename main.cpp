#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include "repsearch.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    RepSearch *repSearch = new RepSearch(&app);
    qmlRegisterSingletonInstance("com.company.RepSearch", 1, 0, "RepSearch", repSearch);

    const QUrl url(u"qrc:/Desafio_Destaque/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
