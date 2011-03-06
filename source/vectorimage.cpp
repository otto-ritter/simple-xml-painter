#include "vectorimage.h"

VectorImage::VectorImage()
{
}

VectorImage::~VectorImage()
{
}

void VectorImage::clear()
{
    foreach(Element* element, m_elements)
       delete element;
    m_elements.clear();
}

void VectorImage::addElement(Element* element)
{
    m_elements.push_back(element);
    emit changed();
}

QList<Element*> VectorImage::elements()
{
    return m_elements;
}
