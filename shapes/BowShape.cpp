#include "BowShape.h"

#include <QBrush>
#include <QPainterPath>
#include <QPen>

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

    const QRectF leftWingRect(x, y + h * 0.15, w * 0.45, h * 0.7);
    const QRectF rightWingRect(x + w * 0.55, y + h * 0.15, w * 0.45, h * 0.7);
    const QRectF centerKnotRect(x + w * 0.42, y + h * 0.32, w * 0.16, h * 0.36);

    QPainterPath leftWing;
    leftWing.moveTo(leftWingRect.right(), leftWingRect.center().y());
    leftWing.quadTo(leftWingRect.left(), leftWingRect.top(), leftWingRect.left(), leftWingRect.center().y());
    leftWing.quadTo(leftWingRect.left(), leftWingRect.bottom(), leftWingRect.right(), leftWingRect.center().y());

    QPainterPath rightWing;
    rightWing.moveTo(rightWingRect.left(), rightWingRect.center().y());
    rightWing.quadTo(rightWingRect.right(), rightWingRect.top(), rightWingRect.right(), rightWingRect.center().y());
    rightWing.quadTo(rightWingRect.right(), rightWingRect.bottom(), rightWingRect.left(), rightWingRect.center().y());

    painter.setPen(QPen(Qt::black, 2));
    painter.setBrush(QBrush(m_color));
    painter.drawPath(leftWing);
    painter.drawPath(rightWing);

    painter.setBrush(QBrush(Qt::yellow));
    painter.drawEllipse(centerKnotRect);
}

QRectF BowShape::boundingRect() const
{
    return QRectF(m_position, m_size);
}
