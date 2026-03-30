#pragma once

#include "GraphicObject.h"

class IsoscelesTriangle : public GraphicObject
{
public:
    IsoscelesTriangle(const QPointF &position, const QSizeF &size, double speed, const QColor &color);

    void draw(QPainter &painter) const override;
    QRectF boundingRect() const override;

private:
    QSizeF m_size;
};
