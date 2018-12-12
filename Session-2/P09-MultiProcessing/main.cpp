#include <QCoreApplication>
#include <QProcess>
#include <QtDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "Main process ID: " << a.applicationPid() << std::endl;

    QProcess process;

    QStringList args; //QList<QString>
    args << "--version";

    process.setProgram("/usr/local/bin/gzip");
    process.setArguments(args);

    process.start();
    process.waitForStarted();

    std::cout << "Process Started: " << process.processId() << std::endl;
    process.waitForReadyRead();
    std::cout << process.readAll().toStdString() << std::endl;

    int m;
    std::cin >> m;
    std::cout << "You typed a number " << m << std::endl;
    process.close();

    return a.exec();
}
