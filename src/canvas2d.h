#pragma once

#include <QWidget>

// You are NOT supposed to modify this file.

class Canvas2D : public QWidget
{
    Q_OBJECT
public:
    Canvas2D(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());

    void paintEvent(QPaintEvent *event);

private:
    const int width = 768;
    const int height = 512;

    QImage m_image;

    void initializeImage();
};
