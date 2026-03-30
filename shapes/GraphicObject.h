#pragma once

#include <QColor>
#include <QPainter>
#include <QPointF>
#include <QRectF>

class GraphicObject
{
public:
    GraphicObject(const QPointF &position, double speed, const QColor &color);
    virtual ~GraphicObject() = default;

    virtual void draw(QPainter &painter) const = 0;
    virtual QRectF boundingRect() const = 0;

    void moveWithin(int topBoundary, int bottomBoundary);
    virtual void reset();

protected:
    QPointF m_position;
    QPointF m_initialPosition;
    double m_speed;
    double m_initialSpeed;
    int m_direction;
    int m_initialDirection;
    QColor m_color;
};
