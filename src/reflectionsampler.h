#pragma once

#include <QImage>
#include <QString>
#include <glm/glm.hpp>

// You are NOT supposed to modify this file.

class Sampler
{
public:
    Sampler(QString path);
    glm::vec4 getReflection(glm::vec3 pos, glm::vec3 dir) const;

private:
    QImage background;
    glm::vec4 interpolate(float x, float y) const;
    glm::vec4 Qc2vec(QColor c) const;
    float h_ratio;
    float w_ratio;
};
