#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *newLabel = new QLabel("Hello New Tab", this);
    ui->tabWidget->addTab(newLabel, "new Tab");

    ui->tabWidget->removeTab(2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
