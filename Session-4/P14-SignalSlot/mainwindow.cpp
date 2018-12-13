#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(this, &MainWindow::init,
                     this, &MainWindow::onInit);
    emit init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onInit()
{
    qDebug("Inited;");
}
