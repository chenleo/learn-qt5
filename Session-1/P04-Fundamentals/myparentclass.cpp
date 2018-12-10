#include "myparentclass.h"
#include "QCoreApplication"

MyParentClass::MyParentClass(QObject *parent) : QObject(parent)
{

}

MyParentClass::~MyParentClass()
{
    qDebug("MyParentClass destructor!");
    QCoreApplication::quit();

}
