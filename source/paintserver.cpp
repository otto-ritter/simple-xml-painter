#include "paintserver.h"

PaintServer& PaintServer::instance()
{
    static PaintServer paintServer;
    return paintServer;
}

PaintServer::PaintServer()
{
}

PaintServer::~PaintServer()
{
}

void PaintServer::setColor(QColor color)
{
    m_color = color;
    emit notifyObservers();
}

QColor PaintServer::color()
{
    return m_color;
}
