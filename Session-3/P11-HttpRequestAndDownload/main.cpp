#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager man;

    //return the content
//    QNetworkRequest req(QUrl("http://blog.qt.io/"));

////    QString user_agent("Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_0) "
////                       "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 "
////                       "Safari/537.36");
//    QString user_agent("HttpRequestDemo/0.1 (Win64) Qt/5.7");
//    req.setHeader(QNetworkRequest::UserAgentHeader, QVariant(user_agent));

//    QNetworkReply *reply = man.get(req);

//    QObject::connect(reply, &QNetworkReply::finished,
//                     [&](){
//        // reply is still open for reading after emitting "finished" signal
//        QByteArray read = reply->readAll();
//        std::cout << "Got response:\n"
//                  << read.toStdString()
//                  << std::endl;
//        reply->close();
//        reply->deleteLater();
//        a.quit();
//    });

    //Save the page to file:
    QNetworkRequest req(QUrl("http://www.gnu.org/licenses/lgpl-3.0.txt"));
    QString user_agent("HttpRequestDemo/0.1 (Win64) Qt/5.7");
    req.setHeader(QNetworkRequest::UserAgentHeader, QVariant(user_agent));
    QNetworkReply *reply = man.get(req);
    QObject::connect(reply, &QNetworkReply::finished,
                     [&](){
        // reply is still open for reading after emitting 'finished' signal
        QByteArray read = reply->readAll();
        QFile out("lgpl-3_0.txt");
        out.open(QIODevice::WriteOnly | QIODevice::Text);
        out.write(read);
        out.close();
        reply->close();
        reply->deleteLater();
        a.quit();
    });


    return a.exec();
}
