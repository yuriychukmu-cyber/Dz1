#include "MainWindow.h"

#include "CanvasWidget.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      m_canvas(new CanvasWidget(this)),
      m_statusLabel(new QLabel(QStringLiteral("Анимация остановлена"), this)),
      m_startButton(new QPushButton(QStringLiteral("Старт"), this)),
      m_stopButton(new QPushButton(QStringLiteral("Стоп"), this)),
      m_resetButton(new QPushButton(QStringLiteral("Сброс"), this)),
      m_exitButton(new QPushButton(QStringLiteral("Выход"), this))
{
    setWindowTitle(QStringLiteral("Движение графических объектов — Qt Widgets"));
    resize(860, 560);

    auto *central = new QWidget(this);
    auto *mainLayout = new QVBoxLayout(central);

    auto *instruction = new QLabel(QStringLiteral("Нажмите «Старт» для запуска одновременного вертикального движения фигур."), this);
    instruction->setWordWrap(true);

    auto *controlsLayout = new QHBoxLayout();
    controlsLayout->addWidget(m_startButton);
    controlsLayout->addWidget(m_stopButton);
    controlsLayout->addWidget(m_resetButton);
    controlsLayout->addStretch();
    controlsLayout->addWidget(m_exitButton);

    m_statusLabel->setMinimumWidth(220);

    mainLayout->addWidget(instruction);
    mainLayout->addWidget(m_canvas, 1);
    mainLayout->addLayout(controlsLayout);
    mainLayout->addWidget(m_statusLabel);

    setCentralWidget(central);

    connect(m_startButton, &QPushButton::clicked, m_canvas, &CanvasWidget::startAnimation);
    connect(m_stopButton, &QPushButton::clicked, m_canvas, &CanvasWidget::stopAnimation);
    connect(m_resetButton, &QPushButton::clicked, m_canvas, &CanvasWidget::resetAnimation);
    connect(m_exitButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(m_canvas, &CanvasWidget::animationStateChanged, m_statusLabel, &QLabel::setText);
}
