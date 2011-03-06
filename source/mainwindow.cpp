#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMouseEvent"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    moveColorSlider();
    connect(ui->hSliderAlpha,SIGNAL(sliderReleased()),this,SLOT(moveColorSlider()));
    connect(ui->hSliderRed,SIGNAL(sliderReleased()),this,SLOT(moveColorSlider()));
    connect(ui->hSliderBlue,SIGNAL(sliderReleased()),this,SLOT(moveColorSlider()));
    connect(ui->hSliderGreen,SIGNAL(sliderReleased()),this,SLOT(moveColorSlider()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::moveColorSlider()
{
    paintcolor=QColor(ui->hSliderRed->value(),ui->hSliderGreen->value(),ui->hSliderBlue->value(),ui->hSliderAlpha->value());
    setColorPreview(paintcolor);
    setHtlmColor(paintcolor);
}
void MainWindow::setColorPreview(QColor bgcolor)
{
    QPalette palette;
    palette.setColor(QPalette::Background,bgcolor);
    // Palette setzen
    ui->label_colorPre->setPalette(palette);
}
void MainWindow::setHtlmColor(QColor bgcolor)
{
    QString htmlcolor;
    htmlcolor.append("#");
    htmlcolor.append(QString::number(bgcolor.red(),16).rightJustified(2,48,false));
    htmlcolor.append(QString::number(bgcolor.green(),16).rightJustified(2,48,false));
    htmlcolor.append(QString::number(bgcolor.blue(),16).rightJustified(2,48,false));
    ui->lineEditHtmlColor->setText(htmlcolor);
    //bgcolor.red();
}
