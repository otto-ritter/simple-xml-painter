#ifndef PAINTFRAME_H
#define PAINTFRAME_H

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QFrame>
#include <QMouseEvent>
class paintFrame : public QWidget
{
    Q_OBJECT
public:
    explicit paintFrame(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void mousePressEvent(QMouseEvent *event);
    void updateImage();

private:
    int lastClick[2];
    int currentClick[2];
};

#endif // PAINTFRAME_H
