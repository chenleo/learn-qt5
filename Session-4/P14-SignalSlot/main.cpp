#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //lambda style
    QObject::connect(&w, &MainWindow::destroyed, [&](){
        qDebug("Main window destroyed!");
    });
    w.show();

    return a.exec();
}
