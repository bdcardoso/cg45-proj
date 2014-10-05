#pragma once

#include "opengl.h"
#include "vector3.h"

class perspective_camera {

    GLdouble _fovy, _aspect;

public:
    perspective_camera(GLdouble fovy, GLdouble aspect);

    void update();

    void compute_projection_matrix();

    void compute_visualization_matrix();


};