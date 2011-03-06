#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QDebug"
#include <QMainWindow>
#include <QColor>
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected slots:
    void showColor();
    void updateColors();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
