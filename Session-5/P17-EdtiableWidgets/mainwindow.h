#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool plainText;

private slots:
    void updateTextBrowser();
    void onComboboxCurrenttextchanged(const QString &text);
};

#endif // MAINWINDOW_H
