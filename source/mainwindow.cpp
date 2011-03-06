#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMouseEvent"
#include "paintserver.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showColor();
    connect(ui->hSliderAlpha,SIGNAL(valueChanged(int)),this,SLOT(showColor()));
    connect(ui->hSliderRed,SIGNAL(valueChanged(int)),this,SLOT(showColor()));
    connect(ui->hSliderBlue,SIGNAL(valueChanged(int)),this,SLOT(showColor()));
    connect(ui->hSliderGreen,SIGNAL(valueChanged(int)),this,SLOT(showColor()));

    connect(&PaintServer::instance(), SIGNAL(notifyObservers()), this, SLOT(updateColors()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showColor()
{
    QColor color = QColor( ui->hSliderRed->value(),
                           ui->hSliderGreen->value(),
                           ui->hSliderBlue->value(),
                           ui->hSliderAlpha->value() );

    PaintServer::instance().setColor(color);
}

void MainWindow::updateColors()
{
    QColor color = PaintServer::instance().color();
    // Update preview widget with new color
    ui->label_colorPre->setPalette(QPalette(QPalette::Background, color));

    QString htmlcolor;
    htmlcolor.append("#");
    htmlcolor.append(QString::number(color.red(),16).rightJustified(2,48,false));
    htmlcolor.append(QString::number(color.green(),16).rightJustified(2,48,false));
    htmlcolor.append(QString::number(color.blue(),16).rightJustified(2,48,false));
    ui->lineEditHtmlColor->setText(htmlcolor);
    //bgcolor.red();
}
