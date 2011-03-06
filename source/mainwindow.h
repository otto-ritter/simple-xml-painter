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
    QColor paintcolor;
protected slots:
    void moveColorSlider();
private:
    void setHtlmColor(QColor bgcolor);
    void setColorPreview(QColor bgcolor);
    ;
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H