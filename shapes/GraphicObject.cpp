#include "GraphicObject.h"

GraphicObject::GraphicObject(const QPointF &position, double speed, const QColor &color)
    : m_position(position),
      m_initialPosition(position),
      m_speed(speed),
      m_initialSpeed(speed),
      m_direction(1),
      m_initialDirection(1),
      m_color(color)
{
}

void GraphicObject::moveWithin(int topBoundary, int bottomBoundary)
{
    m_position.ry() += m_direction * m_speed;

    QRectF rect = boundingRect();
    if (rect.top() < topBoundary) {
        m_position.ry() += (topBoundary - rect.top());
        m_direction = 1;
    } else if (rect.bottom() > bottomBoundary) {
        m_position.ry() -= (rect.bottom() - bottomBoundary);
        m_direction = -1;
    }
}

void GraphicObject::reset()
{
    m_position = m_initialPosition;
    m_speed = m_initialSpeed;
    m_direction = m_initialDirection;
}
