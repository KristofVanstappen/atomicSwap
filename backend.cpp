#include "backend.h"
#include "documenthandler.h"
#include <QDebug>
#include "ootable.h"

Backend::Backend(QQmlApplicationEngine& engine, QObject *parent) : engine(engine), QObject(parent)
{

}

void Backend::doSomething()
{
    qInfo() << "Do something";

        // Step 1: get access to the root object
    QObject *rootObject = engine.rootObjects().first();
    QObject *qmlObject = rootObject->findChild<QObject*>("button");

    // Step 2a: set or get the desired property value for the root object
    rootObject->setProperty("color", "red");
    qInfo() << rootObject->property("visible");

    // Step 2b: set or get the desired property value for any qml object
    qmlObject->setProperty("visible", false);

    QObject *qmlObject2 = rootObject->findChild<QObject*>("document");
    
    DocumentHandler* docHandler = reinterpret_cast<DocumentHandler*>(qmlObject2);

    docHandler->loadTemplated(QUrl("qrc:/pages/ootable.html"), new Ootable("een nieuw tekstje"));
    
    //qDebug() << qmlObject->property("visible");
    
}

void Backend::doSomethingElse(QString link)
{
    //engine.load(QUrl("qrc:/ootable.qml"));
    qInfo() << "Do something else " << link ;
    
}