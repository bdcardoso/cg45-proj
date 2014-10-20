#pragma once
#include "dynamic_object.h"

class camera : public dynamic_object {
protected:
    vector3 _up, _eye;
    GLdouble _near, _far;

    camera(GLdouble near = 0.0, GLdouble far = 1.0);

public:
    virtual void compute_projection_matrix() = 0;
    virtual void compute_visualization_matrix() = 0;
};
