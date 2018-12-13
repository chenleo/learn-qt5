#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTcpServer server;
    if (!server.listen(QHostAddress::LocalHost, 54321)) {
        qDebug() << "Failed to listen at localhost:54321";
        return 1;
    }
    server.waitForNewConnection(-1); // -1: no time out
    QTcpSocket *con = server.nextPendingConnection();
    QByteArray toWrite("Hello From Server");
    con->write(toWrite);
    con->waitForBytesWritten();
    con->waitForReadyRead();
    QByteArray readData = con->readAll();
    qDebug() << "Server reads" << readData;
    con->close();
    con->deleteLater();
    server.close();

    qDebug() << "Bye";

    return a.exec();
}
