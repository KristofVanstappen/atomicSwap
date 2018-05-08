#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QQmlApplicationEngine>

class Backend : public QObject
{
    Q_OBJECT
private: 
    QQmlApplicationEngine& engine;
public:
    explicit Backend(QQmlApplicationEngine& engine, QObject *parent = 0);
    

public slots:
    void doSomething();
    void doSomethingElse(QString link);
};

#endif // BACKEND_H