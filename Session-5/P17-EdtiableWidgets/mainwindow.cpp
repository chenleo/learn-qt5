#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->plainText = true;
    ui->setupUi(this);

    QObject::connect(ui->comboBox, &QComboBox::currentTextChanged,
                     this, &MainWindow::onComboboxCurrenttextchanged);
    QObject::connect(ui->textEdit, &QTextEdit::textChanged,
                     this, &MainWindow::updateTextBrowser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTextBrowser()
{
    QString text = ui->textEdit->document()->toPlainText();
    if (plainText) {
        ui->textBrowser->setPlainText(text);
    } else {
        ui->textBrowser->setHtml(text);
    }
}

void MainWindow::onComboboxCurrenttextchanged(const QString &text)
{
    plainText = (text == "Plain");
    this->updateTextBrowser();
}
