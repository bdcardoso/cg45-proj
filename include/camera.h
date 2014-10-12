#pragma once
#include "entity.h"
#include "vector3.h"
#include "opengl.h"

class camera : public entity {
protected:
    vector3 _up, _eye;
    GLdouble _near, _far;

public:
    camera(GLdouble near, GLdouble far);

    virtual void compute_projection_matrix() = 0;
    virtual void compute_visualization_matrix() = 0;
    virtual void update(glut_time_t dt) = 0;
};

