#include "IsoscelesTriangle.h"

#include <QBrush>
#include <QPen>
#include <QPolygonF>

IsoscelesTriangle::IsoscelesTriangle(const QPointF &position, const QSizeF &size, double speed, const QColor &color)
    : GraphicObject(position, speed, color),
      m_size(size)
{
}

void IsoscelesTriangle::draw(QPainter &painter) const
{
    QPolygonF triangle;
    triangle << QPointF(m_position.x() + m_size.width() / 2.0, m_position.y())
             << QPointF(m_position.x(), m_position.y() + m_size.height())
             << QPointF(m_position.x() + m_size.width(), m_position.y() + m_size.height());

    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(m_color));
    painter.drawPolygon(triangle);
}

QRectF IsoscelesTriangle::boundingRect() const
{
    return QRectF(m_position, m_size);
}
