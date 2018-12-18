#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //engine.addImportPath("the projects");
    // then import module in main.qml


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


// make a qmldir file
// module MyPage
// Page1 1.0 Page1.qml
// Page1 1.1 Page1_1.1.qml

// import
