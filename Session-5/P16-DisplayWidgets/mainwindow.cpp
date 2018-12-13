#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    const QString textSrc("Hello World. This is some demo text"
//                          ". This doesn't mean much, but we will test the "
//                          "lable widget and the text browser widget.");
//    ui->label->setText(textSrc);
    //ui->textBrowser->setText(textSrc);

//    QPixmap pic;
//    pic.load("/Users/maverick/Desktop/owl.jpg");
//    ui->label->setPixmap(pic);
//    ui->label->resize(200, 200); //does not work;

    QTimer *timer = new QTimer(this);
    timer->setInterval(500);
    QObject::connect(timer, &QTimer::timeout,
                     this, &MainWindow::onTimeOut);
    timer->start();
    //timer->setSingleShot(true); only once


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeOut()
{
    int value = ui->progressBar->value();
    if (value >= 100) {
        return;
    }
    value += 1;
    ui->progressBar->setValue(value);
}
