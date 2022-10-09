#include <string>
#include <iostream>
#include <fstream>
#include <QCoreApplication>
#include <QFile>
#include <QPainter>
#include <QString>
#include <QRgb>

#include "canvas2d.h"
#include "lightmodel.h"
#include "rgba.h"

// This file handles Qt interfaces that visualize our image.
// You are NOT supposed to modify this file.

static QRgb toQRgb(const RGBA &color) {
    return qRgba(color.r, color.g, color.b, color.a);
}

Canvas2D::Canvas2D(QWidget* parent, Qt::WindowFlags f) : QWidget(parent, f) {
    setFixedSize(width, height);

    m_image = QImage(width, height, QImage::Format_RGBX8888);
    m_image.fill(Qt::black);

    initializeImage();
}

void Canvas2D::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(QPoint(0, 0), m_image);
}

void Canvas2D::initializeImage() {
    // define light sources
    std::vector<LightInfo> lights;
    lights.clear();
    lights.push_back(LightInfo{glm::vec4(0.99, 0.99, 0.99, 1), glm::vec3(2, 2, 2)});
    lights.push_back(LightInfo{glm::vec4(0.99, 0.99, 0.99, 1), glm::vec3(-4, 4, 4)});

    Sampler reflectionSampler(QString(":/resources/background.png"));

    // load intersection data
    std::string dataPath = QCoreApplication::applicationDirPath().toStdString() + "/intersections.dat";
    QFile::copy(QString(":/resources/intersections.dat"), dataPath.c_str());
    std::ifstream inFile(dataPath, std::ios::in | std::ios::binary);

    PixelInfo info;
    RGBA color{0,0,0};
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            inFile.read((char *)&info, sizeof(info));

            // get color with phong model
            if (info.intersect) {
                color = phong(info.position, info.normal, info.sight, info.material, lights, reflectionSampler);
            } else {
                color = RGBA{0,0,0};
            }

            m_image.setPixel(i, j, toQRgb(color));
        }
    }
}

