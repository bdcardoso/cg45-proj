#include "material.h"

material::material(const vector4 &ambient, const vector3 &diffuse,
                   const vector3 &specular, const vector3::scalar_t shininess)
        : ambient_(ambient),
          diffuse_(diffuse),
          specular_(specular),
          shininess_(shininess * 128.0) {}

const vector4 &material::ambient() const { return ambient_; }
const vector3 &material::diffuse() const { return diffuse_; }
const vector3 &material::specular() const { return specular_; }
vector3::scalar_t material::shininess() const { return shininess_; }

void material::use() const {
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient().get());
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse().get());
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular().get());
    glMaterialf(GL_FRONT, GL_SHININESS, shininess());
}
