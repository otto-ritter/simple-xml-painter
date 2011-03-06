#include "paintframe.h"

paintFrame::paintFrame(QWidget *parent) :
    QWidget(parent)
{
   x=y=mButton = 0;
}
void paintFrame::mousePressEvent(QMouseEvent *event)
{
    mButton = event->button();
    x = event->x();
    y = event->y();

    update();

}
 void paintFrame::paintEvent(QPaintEvent *)
 {
    QPainter painter(this);
    painter.setPen(QPen(Qt::green,3));

    painter.drawLine(x,y,x+10,y+20);
    painter.end();
 }
