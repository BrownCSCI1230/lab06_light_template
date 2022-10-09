#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "param.h"
#include "reflectionsampler.h"
#include "rgba.h"

// You are NOT supposed to modify this file.

RGBA phong(glm::vec3 position, glm::vec3 normal, glm::vec3 directionToCamera,
           const Material &material, const std::vector<LightInfo> &lights, const Sampler &reflectionSampler);
