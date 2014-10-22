#include "perspective_camera.h"

perspective_camera::perspective_camera(GLdouble fovy, GLdouble aspect,
                                       GLdouble near, GLdouble far)
        : fovy_(fovy), aspect_(aspect), camera::camera(near, far) {}

void perspective_camera::reshape(int w, int h) {}

void perspective_camera::compute_projection_matrix() {
    gluPerspective(fovy_, aspect_, near_, far_);
}

void perspective_camera::compute_visualization_matrix() {
    vector3 eye(0.0, 3.0, 2.0);
    vector3 at(0.0, 0.0, 0.0);

    gluLookAt(eye.x(), eye.y(), eye.z(), at.x(), at.y(), at.z(), 0.0, 1.0, 0.0);
}
