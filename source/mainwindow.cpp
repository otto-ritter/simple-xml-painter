#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMouseEvent"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showColor()
{
    paintcolor = QColor( ui->hSliderRed->value(),
                         ui->hSliderGreen->value(),
                         ui->hSliderBlue->value(),
                         ui->hSliderAlpha->value() );

    // Update preview widget with new color
    ui->label_colorPre->setPalette(QPalette(QPalette::Background, paintcolor));

    setHtlmColor(paintcolor);
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
