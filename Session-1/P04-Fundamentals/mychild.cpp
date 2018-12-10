#include "mychild.h"

MyChild::MyChild(QObject *parent) : QObject(parent)
{

}

MyChild::~MyChild()
{
    qDebug("MyChildClass Destructive!");
}
