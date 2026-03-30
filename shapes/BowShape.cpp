#include "BowShape.h"

#include <QPen>
#include <QPolygonF>

BowShape::BowShape(const QPointF &position, const QSizeF &size, double speed, const QColor &color)
    : GraphicObject(position, speed, color),
      m_size(size)
{
}

void BowShape::draw(QPainter &painter) const
{
    const double x = m_position.x();
    const double y = m_position.y();
    const double w = m_size.width();
    const double h = m_size.height();

    const QPointF leftTop(x, y);
    const QPointF leftBottom(x, y + h);
    const QPointF center(x + w / 2.0, y + h / 2.0);
    const QPointF rightTop(x + w, y);
    const QPointF rightBottom(x + w, y + h);

    painter.setPen(QPen(m_color, 3));
    painter.setBrush(Qt::NoBrush);

    QPolygonF leftTriangle;
    leftTriangle << leftTop << leftBottom << center;

    QPolygonF rightTriangle;
    rightTriangle << rightTop << rightBottom << center;

    painter.drawPolygon(leftTriangle);
    painter.drawPolygon(rightTriangle);
}

QRectF BowShape::boundingRect() const
{
    return QRectF(m_position, m_size);
}
