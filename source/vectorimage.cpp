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
