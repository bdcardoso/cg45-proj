#pragma once

#include "opengl.h"
#include "vector3.h"


class camera {
protected:

    vector3 _up, _at;
    GLdouble _near, _far;

public:

    camera(GLdouble near, GLdouble far);

    void update();
    void compute_projection_matrix();
    void computevisualizationmatrix();
};
