#include "Page.h"
#include <QString>
#include <QTextCodec>
#include <QTextDocument>

#include <QFile>
#include <QFileInfo>
#include <QFileSelector>
#include <QQmlFile>
#include <QQmlFileSelector>
#include <QQuickTextDocument>
#include <QTextCharFormat>
#include <QTextCodec>
#include <QTextDocument>

class Ootable : public Page
{

  private:
    QVariantHash contact;
    QString pageContent;
    
    
    void LoadPage()
    {
       // const QUrl path = QQmlFileSelector::get(engine)->selector()->select(fileUrl);
        const QString fileName = QQmlFile::urlToLocalFileOrQrc("qrc://pages/ootable/ootable.html");
        if (QFile::exists(fileName))
        {
            QFile file(fileName);
            if (file.open(QFile::ReadOnly))
            {
                QByteArray data = file.readAll();
                QTextCodec *codec = QTextCodec::codecForHtml(data);
           
                this->pageContent = codec->toUnicode(data);
          
            }
        }
    }

  public:
    Ootable(QString title)
    {
        this->contact["test"] = title;
        this->LoadPage();
    }

    QString getContent() override
    {
        qInfo() << " getcontent ootable";
        Mustache::QtVariantContext context(this->contact);
        return this->renderer.render(pageContent, &context);
    }
};