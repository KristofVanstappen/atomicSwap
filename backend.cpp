#include "backend.h"

#include <QDebug>
#include <QUrlQuery>
#include "pages/ootable/Ootable.h"

Backend::Backend(QQmlApplicationEngine& engine, QObject *parent) : engine(engine), QObject(parent)
{

        // Step 1: get access to the root object
    

//    docHandler->loadTemplated(QUrl("qrc:/pages/ootable.html"), new Ootable("een nieuw tekstje"));
    
}

void Backend::doSomething()
{
    
    //qDebug() << qmlObject->property("visible");
    
}

void Backend::doSomethingElse(QString link)
{   
    QObject *rootObject = engine.rootObjects().first();

    QObject *qmlObject2 = rootObject->findChild<QObject*>("document");
    
    docHandler = reinterpret_cast<DocumentHandler*>(qmlObject2);

    qInfo() << "Load link";
     

    
    

    QStringList pieces = link.split( "?" );
    QUrl url = QUrl(link);
    QUrlQuery query(url);

    qInfo() << "test == " << query.queryItemValue("tekst");
    if(pieces[0] == QString("ootable")){

         docHandler->loadTemplated(QUrl("qrc:/pages/ootable.html"), new Ootable(query.queryItemValue("tekst")));
    }

    //engine.load(QUrl("qrc:/ootable.qml"));
    qInfo() << "Do something else " << link ;
    
}