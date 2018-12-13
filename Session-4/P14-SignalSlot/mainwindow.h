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

// define a signal signature, do not need to implement
signals:
    void init();

private:
    Ui::MainWindow *ui;

private slots:
    void onInit();
};

#endif // MAINWINDOW_H
