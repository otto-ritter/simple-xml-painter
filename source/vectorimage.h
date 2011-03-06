#ifndef VECTOR_IMAGE_H
#define VECTOR_IMAGE_H

#include <QList>
#include <QPoint>
#include <QColor>

class Element
{
public:
    enum Type
    {
        Line
    };

    virtual Type type() = 0;
};

class Line : public Element
{
public:
    Type type() { return Element::Line; }
    QPoint points[2];
    double strokeWidth;
    QColor color;
};

class VectorImage : public QObject
{
    Q_OBJECT
public:
    VectorImage();
    ~VectorImage();
    void clear();
    void addElement(Element* element);
    QList<Element*> elements();

signals:
    void changed();

private:
    QList<Element*> m_elements;
};

#endif // VECTOR_IMAGE_H
