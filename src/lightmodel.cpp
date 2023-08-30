#include "lightmodel.h"
#include <cmath>
#include <iostream>

// This file contains the phong function you need to fill in.
// This should be the ONLY file you modify.

// Helper function to convert illumination to RGBA, applying some form of tone-mapping (e.g. clamping) in the process
RGBA toRGBA(const glm::vec4 &illumination) {
    // Task 1

    return RGBA{0, 0, 0};
}

// Calculates the RGBA of a pixel from intersection infomation and globally-defined coefficients
RGBA phong(glm::vec3  position,
           glm::vec3  normal,
           glm::vec3  directionToCamera,
           Material  &material,
           std::vector<LightInfo> &lights,
           Sampler   &reflectionSampler) {
    // Normalizing directions
    normal            = glm::normalize(normal);
    directionToCamera = glm::normalize(directionToCamera);

    // Output illumination (we can ignore opacity)
    glm::vec4 illumination(0, 0, 0, 1);

    // Task 3: add the ambient term

    for (const LightInfo &light : lights) {
        // Task 6: compute the attenuation factor

        // Task 4, task 6: add the diffuse term

        // Task 5, task 6: add the specular term
    }

    // Task 7: uncomment the following lines and correct the reflection term.
    //      The following code uses Sampler::getReflection(glm::vec3 startPosition, glm::vec3 lightDirection)
    //      to get the reflection intensity when "recursively raytracing" in some direction from some position

//    glm::vec3 reflectedRay = directionToCamera - 2.f*glm::dot(directionToCamera, normal)*normal; // <-- fix this calculation
//    illumination += kr * reflectionSampler.getReflection(position, reflectedRay);                 // <-- do NOT touch this line

    RGBA returnValue = toRGBA(illumination);
    return returnValue;
}
