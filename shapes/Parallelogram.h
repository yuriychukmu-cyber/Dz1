#pragma once

#include "GraphicObject.h"

class Parallelogram : public GraphicObject
{
public:
    Parallelogram(const QPointF &position, const QSizeF &size, double skewShift, double speed, const QColor &color);

    void draw(QPainter &painter) const override;
    QRectF boundingRect() const override;

private:
    QSizeF m_size;
    double m_skewShift;
};
