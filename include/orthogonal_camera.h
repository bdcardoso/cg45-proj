#pragma once
#include "camera.h"
#include "vector3.h"
#include "opengl.h"

class orthogonal_camera : public camera {
    GLdouble left_, right_, bottom_, top_;

public:
    orthogonal_camera(GLdouble left = -1.0, GLdouble right = 1.0,
                      GLdouble bottom = -1.0, GLdouble top = 1.0,
                      GLdouble near = 0.0, GLdouble far = 1.0);

    void reshape(int w, int h) override;
    void compute_projection_matrix() override;
    void compute_visualization_matrix() override;
};
