#include "paintframe.h"
#include "paintserver.h"

paintFrame::paintFrame(QWidget *parent) :
    QWidget(parent)
{
    currentClick[0] = 0;
    currentClick[1] = 0;
}
void paintFrame::mousePressEvent(QMouseEvent *event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        lastClick[0] = currentClick[0];
        lastClick[1] = currentClick[1];

        currentClick[0] = event->x();
        currentClick[1] = event->y();
        break;
    }

    update();
}
 void paintFrame::paintEvent(QPaintEvent *)
 {
    QPainter painter(this);
    painter.setPen(QPen(PaintServer::instance().color()));

    painter.drawLine( lastClick[0],
                      lastClick[1],
                      currentClick[0],
                      currentClick[1]);
    painter.end();
 }
