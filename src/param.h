#pragma once

#include "glm.hpp"
#include "rgba.h"

/*
 * This file contains the parameters and data structures that you
 * will be working with.
 * You are NOT supposed to modify this file.
 */
const float ka = 0.5;   // Weight for ambient light
const float kd = 0.5;   // Weight for diffuse light
const float ks = 0.5;   // Weight for specular light
const float kr = 0.2;   // Weight for mirror reflection

const float c1 = 1;     // Attenuation coefficient 1
const float c2 = 0.05;  // Attenuation coefficient 2
const float c3 = 0.06;  // Attenuation coefficient 3

struct Material
{
    glm::vec4 diffuse;   // Diffuse color of surface/object material
    glm::vec4 ambient;   // Ambient color of surface/object material
    glm::vec4 specular;  // Specular color of surface/object material
    int shininess;       // Shininess of surface/object material
};

struct LightInfo
{
    glm::vec4 color;     // Point light color
    glm::vec3 source;    // Point light source position
};

// The struct of 2D array data we load. You won't use this directly.
struct pixel_info
{
    glm::vec3 position;   // Position of intersection point
    glm::vec3 normal;     // Surface normal of intersection point
    glm::vec3 sight;      // Direction from intersection point to camera
    Material material;    // Material of surface at intersection point
    bool intersect=false; // Whether intersect
};
