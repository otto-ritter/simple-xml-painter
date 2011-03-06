#include "paintframe.h"
#include "paintserver.h"

paintFrame::paintFrame(QWidget *parent) :
    QWidget(parent)
{
    currentClick[0] = 0;
    currentClick[1] = 0;

    connect(&PaintServer::instance(), SIGNAL(notifyObservers()), this, SLOT(updateImage()));
}

void paintFrame::mousePressEvent(QMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        Line* line = new Line();
        lastClick[0] = currentClick[0];
        lastClick[1] = currentClick[1];

        currentClick[0] = event->x();
        currentClick[1] = event->y();
        line->points[0].setX(lastClick[0]);

        line->points[0].setY(lastClick[1]);
        line->points[1].setX(currentClick[0]);
        line->points[1].setY(currentClick[1]);

        PaintServer::instance().vectorImage().addElement(line);
        break;
    }

    update();
}

void paintFrame::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    VectorImage& vectorImage = PaintServer::instance().vectorImage();
    QList<Element*> elements = vectorImage.elements();

    foreach(Element* element, elements)
    {
       switch(element->type())
       {
       case Element::Line:
           Line* line = dynamic_cast<Line*>(element);
           painter.setPen(QPen(PaintServer::instance().color(), line->strokeWidth));
           painter.drawLine(line->points[0], line->points[1]);
           break;
       }
    }

    painter.end();
}

void paintFrame::updateImage()
{
    update();
}
