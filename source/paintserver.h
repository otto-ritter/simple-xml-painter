#ifndef PAINT_SERVER_H
#define PAINT_SERVER_H

#include <QObject>
#include <QColor>
#include "vectorimage.h"

class PaintServer : public QObject
{
    Q_OBJECT
public:
    static PaintServer& instance();

    void setColor(QColor color);
    QColor color();

    VectorImage& vectorImage();

public slots:
    void reportChanges();

signals:
    void notifyObservers();

private:
    PaintServer();
    ~PaintServer();

    QColor m_color;
    VectorImage m_vectorImage;
};

#endif // PAINT_SERVER_H
