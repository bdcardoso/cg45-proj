#pragma once

#include "opengl.h"
#include "vector3.h"

class orthogonal_camera {

    GLdouble _left, _right, _bottom, _top;

public:
    orthogonal_camera(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);

    void update();

    void compute_projection_matrix();

    void compute_visualization_matrix();


};