#include "pages/Page.h"
#include <QString>
#include <QTextCodec>
#include <QTextDocument>

class Ootable : public Page
{

  private:
  QString title;
  public:
    Ootable(QString title) : title(title)
    {
        qInfo() << "construct ootable";   
        this->loadPage(QString("qrc://pages/ootable/ootable.html"));
    }

    QString createTable(){
       qInfo() << "create table ootable";
        auto fragment = this->loadFragment(QString("qrc://pages/ootable/orderTable.html"));
        QString content = QString("");
  
        for(int i = 0; i<10; i++){
            QVariantHash order;
            order["c1"] = "value 1";
            order["c2"] = "value 2";
            order["c3"] = "value 3";
            order["c4"] = "value 4";
            Mustache::QtVariantContext context(order);
            content.append(this->renderer.render(fragment, &context));

        }
      //  }
    
        return content;
    }
    
    QString getContent() override
    {
        qInfo() << " getcontent ootable" << title;
        QVariantHash fragments;
        fragments["ROWS"] = createTable();
        fragments["tekst"] = title;
        Mustache::QtVariantContext context(fragments);

        qInfo() <<  this->renderer.render(pageContent, &context);
        return this->renderer.render(pageContent, &context);
    }
};