#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <dialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionmyAction, &QAction::triggered,
                     this, &MainWindow::onShowPopup);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onShowPopup()
{
    Dialog *popup = new Dialog(this);
    //popup->exec();  //Modal, block other windows
    popup->show();
    qDebug("onShowPopup");
}
