
#ifndef PAGE_H
#define PAGE_H

#include <QString>
#include "mustache.h"
class Page {
protected:
    Mustache::Renderer renderer;
    

public:
    virtual QString getContent() = 0;

};


#endif