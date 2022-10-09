#include "lightmodel.h"
#include <cmath>

// This file contains the phong function you need to fill in.
// Check detailed explanation about input arguments at lightmodel.cpp
// This should be the ONLY file you modify.
// If you have questions about the variables and structs, refer to
// main.cpp for guidance.

RGBA toRGBA(const glm::vec4 &illumination) {
    // we do not need to think about opacity in this lab
    RGBA out{0, 0, 0};
    // Task 1 - illumination to rgba:

    return out;
}

// calculates RGBA of a pixel with given infomation
RGBA phong(glm::vec3 position, glm::vec3 normal, glm::vec3 directionToCamera,
           const Material &material, const std::vector<LightInfo> &lights, const Sampler &reflectionSampler) {
    glm::vec4 illumination(0, 0, 0, 1);

    // Task 3 - ambient light:

    for (const LightInfo &l : lights) {
        // Task 4:

        // Task 6:

        // Task 4, Task 6:

        // Task 5, Task 6:
    }

    // Task 7:
    // usage for reflection sampler:
    // Sampler::getReflection(glm::vec3 start_position, glm::vec3 light_direction) -> glm::vec4
    // Returns reflection intensity at a direction from start position


    RGBA out = toRGBA(illumination);
    return out;
}
