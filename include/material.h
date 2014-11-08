#pragma once
#include "opengl.h"
#include "vector3.h"
#include "vector4.h"

class material {
    const vector4 ambient_;
    const vector3 diffuse_, specular_;
    const vector3::scalar_t shininess_;

public:
    material(const vector4 &ambient, const vector3 &diffuse,
             const vector3 &specular, const vector3::scalar_t shininess);

    const vector4 &ambient() const;
    const vector3 &diffuse() const;
    const vector3 &specular() const;
    vector3::scalar_t shininess() const;

    void use() const;
};
