#include "Parallelogram.h"

#include <QBrush>
#include <QPen>
#include <QPolygonF>

Parallelogram::Parallelogram(const QPointF &position, const QSizeF &size, double skewShift, double speed, const QColor &color)
    : GraphicObject(position, speed, color),
      m_size(size),
      m_skewShift(skewShift)
{
}

void Parallelogram::draw(QPainter &painter) const
{
    QPolygonF polygon;
    polygon << QPointF(m_position.x() + m_skewShift, m_position.y())
            << QPointF(m_position.x() + m_size.width() + m_skewShift, m_position.y())
            << QPointF(m_position.x() + m_size.width(), m_position.y() + m_size.height())
            << QPointF(m_position.x(), m_position.y() + m_size.height());

    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(m_color));
    painter.drawPolygon(polygon);
}

QRectF Parallelogram::boundingRect() const
{
    return QRectF(m_position.x(), m_position.y(), m_size.width() + m_skewShift, m_size.height());
}
