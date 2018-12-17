#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initDb();
    QSqlTableModel *model = initModel();
    ui->tableView->setModel(model);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDb()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    db.open();
    db.exec("CREATE TABLE price (name Text, price Currency)");
    db.exec("INSERT INTO price (name, price) VALUES('Apple', 2.01)");
    db.exec("INSERT INTO price (name, price) VALUES('Banana', 1.332)");
    db.exec("INSERT INTO price (name, price) VALUES('Orange', 0.60)");
    db.exec("INSERT INTO price (name, price) VALUES('Pear', 1.93)");
}

QSqlTableModel *MainWindow::initModel()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("price");
    model->select();

    model->setHeaderData(0, Qt::Horizontal, "Item Name");
    model->setHeaderData(1, Qt::Horizontal, "Price");
    return model;
}
