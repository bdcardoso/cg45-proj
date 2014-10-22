#pragma once
#include "camera.h"

class perspective_camera : public camera {
    GLdouble fovy_, aspect_;

public:
    perspective_camera(GLdouble fovy = 90.0, GLdouble aspect = 1.0,
                       GLdouble near = 0.0, GLdouble far = 1.0);

    void reshape(int w, int h) override;
    void compute_projection_matrix() override;
};
