#pragma once

#include <QWidget>
#include <QString>

#include <memory>
#include <vector>

class QTimer;
class GraphicObject;

class CanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CanvasWidget(QWidget *parent = nullptr);
    ~CanvasWidget() override;

    void startAnimation();
    void stopAnimation();
    void resetAnimation();
    bool isRunning() const;

signals:
    void animationStateChanged(const QString &statusText);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void advanceFrame();

private:
    void createObjects();

    std::vector<std::unique_ptr<GraphicObject>> m_objects;
    QTimer *m_timer;
};
