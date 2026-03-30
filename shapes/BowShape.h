#pragma once

#include "GraphicObject.h"

class BowShape : public GraphicObject
{
public:
    BowShape(const QPointF &position, const QSizeF &size, double speed, const QColor &color);

    void draw(QPainter &painter) const override;
    QRectF boundingRect() const override;

private:
    QSizeF m_size;
};
