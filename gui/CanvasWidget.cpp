#include "CanvasWidget.h"

#include "../shapes/BowShape.h"
#include "../shapes/GraphicObject.h"
#include "../shapes/IsoscelesTriangle.h"
#include "../shapes/Parallelogram.h"

#include <QPainter>
#include <QTimer>

CanvasWidget::CanvasWidget(QWidget *parent)
    : QWidget(parent),
      m_timer(new QTimer(this))
{
    setMinimumSize(640, 360);
    setAutoFillBackground(true);

    createObjects();

    m_timer->setInterval(25);
    connect(m_timer, &QTimer::timeout, this, &CanvasWidget::advanceFrame);

    emit animationStateChanged(QStringLiteral("Анимация остановлена"));
}

CanvasWidget::~CanvasWidget() = default;

void CanvasWidget::startAnimation()
{
    if (m_timer->isActive()) {
        return;
    }

    m_timer->start();
    emit animationStateChanged(QStringLiteral("Анимация запущена"));
}

void CanvasWidget::stopAnimation()
{
    if (!m_timer->isActive()) {
        return;
    }

    m_timer->stop();
    emit animationStateChanged(QStringLiteral("Анимация остановлена"));
}


void CanvasWidget::resetAnimation()
{
    for (const auto &object : m_objects) {
        object->reset();
    }
    update();
    emit animationStateChanged(m_timer->isActive() ? QStringLiteral("Анимация запущена")
                                                   : QStringLiteral("Анимация остановлена"));
}

bool CanvasWidget::isRunning() const
{
    return m_timer->isActive();
}

void CanvasWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(rect(), QColor(255, 255, 255));

    for (const auto &object : m_objects) {
        object->draw(painter);
    }
}

void CanvasWidget::advanceFrame()
{
    const int topBoundary = 0;
    const int bottomBoundary = height();

    for (const auto &object : m_objects) {
        object->moveWithin(topBoundary, bottomBoundary);
    }

    update();
}

void CanvasWidget::createObjects()
{
    m_objects.clear();
    m_objects.emplace_back(std::make_unique<IsoscelesTriangle>(QPointF(30, 30), QSizeF(70, 95), 2.0, Qt::black));
    m_objects.emplace_back(std::make_unique<Parallelogram>(QPointF(220, 40), QSizeF(120, 58), 28, 2.8, Qt::black));
    m_objects.emplace_back(std::make_unique<BowShape>(QPointF(460, 35), QSizeF(95, 95), 1.6, Qt::black));
}
