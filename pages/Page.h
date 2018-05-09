
#ifndef PAGE_H
#define PAGE_H

#include <QString>

#include <QFile>
#include <QFileInfo>
#include <QFileSelector>
#include <QQmlFile>
#include <QQmlFileSelector>
#include <QQuickTextDocument>
#include <QTextCharFormat>
#include <QTextCodec>
#include <QTextDocument>

#include "mustache.h"
class Page {
protected:
    Mustache::Renderer renderer;
    QString pageContent;

public:

    virtual void loadPage(QString pageName){
        pageContent = this->loadFragment(pageName);
    }

   QString  loadFragment(QString pageName)
    {
       // const QUrl path = QQmlFileSelector::get(engine)->selector()->select(fileUrl);
        const QString fileName = QQmlFile::urlToLocalFileOrQrc(pageName);
        if (QFile::exists(fileName))
        {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly))
            {
                QByteArray data = file.readAll();
                QTextCodec *codec = QTextCodec::codecForHtml(data);
              
                qInfo() << codec->toUnicode(data);
               return codec->toUnicode(data);
          
            }
        }
        //throw
          qInfo() << "file does not exists";
    }

    virtual QString getContent() = 0;

};


#endif