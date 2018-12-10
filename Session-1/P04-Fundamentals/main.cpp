#include <QCoreApplication>
#include "myparentclass.h"
#include "mychild.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyParentClass *my_parent = new MyParentClass();
    MyChild *child = new MyChild(my_parent);           //Once the parent deleted, all child will be deleted.

    //delete my_parent;  plain delete

    // delete when enentloop ends
    my_parent->deleteLater();
    child->deleteLater();



    return a.exec();
}
