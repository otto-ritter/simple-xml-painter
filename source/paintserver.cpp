#include "paintserver.h"

PaintServer& PaintServer::instance()
{
    static PaintServer paintServer;
    return paintServer;
}

PaintServer::PaintServer()
{
    connect(&m_vectorImage, SIGNAL(changed()), this, SLOT(reportChanges()));
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

VectorImage& PaintServer::vectorImage()
{
    return m_vectorImage;
}

void PaintServer::reportChanges()
{
    emit notifyObservers();
}
