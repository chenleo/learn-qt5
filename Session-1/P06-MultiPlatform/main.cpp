#include <QCoreApplication>
#include <QtDebug>
#include <QSysInfo>


void printHello() {
#ifdef Q_OS_WIN
    qDebug() << "Hello Qt on Windows!";
#elif defined (Q_OS_UNIX)
    qDebug() << "Hello Qt on UNIX";    //Mac or linux
#else
    qDebug() << "We do not support this platform yet!";
#endif

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printHello();

    return a.exec();
}
