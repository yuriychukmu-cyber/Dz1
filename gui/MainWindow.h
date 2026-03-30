#pragma once

#include <QMainWindow>

class CanvasWidget;
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    CanvasWidget *m_canvas;
    QLabel *m_statusLabel;
    QPushButton *m_startButton;
    QPushButton *m_stopButton;
    QPushButton *m_resetButton;
    QPushButton *m_exitButton;
};
