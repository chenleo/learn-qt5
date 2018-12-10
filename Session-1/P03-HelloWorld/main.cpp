#include <QCoreApplication>
#include <QtDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //qDebug("Hello Qt World! My %d application.", 1);      without QtDebug
    //qDebug() << "Hello Qt World! My " << 1 << " application.";  //with QtDebug
    std::cout << "Hello Qt World!"<< std::endl;
    return a.exec();
}
