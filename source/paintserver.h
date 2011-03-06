#ifndef PAINT_SERVER_H
#define PAINT_SERVER_H

#include <QObject>
#include <QColor>

class PaintServer : public QObject
{
    Q_OBJECT
public:
    static PaintServer& instance();

    void setColor(QColor color);
    QColor color();

signals:
    void notifyObservers();

private:
    PaintServer();
    ~PaintServer();

    QColor m_color;
};

#endif // PAINT_SERVER_H
