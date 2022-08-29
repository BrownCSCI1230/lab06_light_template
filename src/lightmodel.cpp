#include "lightmodel.h"
#include <math.h>

/*
 * This file contains the phong function you need to fill in.
 * Check detailed explanation about input arguments at lightmodel.cpp
 * This should be the ONLY file you modify.
 * If you have questions about the variables and structs, refer to
 * main.cpp for guidance.
 */


RGBA colorClamp(float illumination[3])
{
    RGBA out(0,0,0,255); // we will not think about opacity(the fourth number) in this lab
    // Task 1 - illumination to rgba:
    return out;
}


// calculates RGBA of a pixel with given infomation
// We use single letters to represent variables for conveniency. Here is the
// detailed explaination:
// p - position of the intersection point
// n - surface normal at the intersection point
// s - the direction from intersection point to camera
// m - material of the intersected object
// lights - array of light data, check param.h for struct info
// refl_sampler - the object you will use for recursive sampling in reflection
RGBA phong(glm::vec3 p, glm::vec3 n, glm::vec3 s, Material m,
           std::vector<LightInfo> lights, Sampler refl_sampler)
{
    glm::vec4 illumination(1,1,1,1);

    // Task 3 - ambient light:
    // remember to replace the initial value of illumination or set it to zero

    for (LightInfo l: lights)
    {
        // Task 6 - attenuation:

        // Task 4 - diffuse light:

        // Task 5 - specular light:
    }

    // Task 7 - reflection:
    /*
     * usage for reflection sampler:
     *          Sampler::getReflection(glm::vec3 start_position, glm::vec3 light_direction) -> glm::vec4
     *          Returns reflection intensity at a direction from start position
     */

    float illu[3] = {illumination.r, illumination.g, illumination.b};
    RGBA out = colorClamp(illu);
    return out;
}
