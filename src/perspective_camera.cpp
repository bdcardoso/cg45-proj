#include "perspective_camera.h"

perspective_camera::perspective_camera(GLdouble fovy, GLdouble aspect, GLdouble near, GLdouble far) :
    _fovy(fovy), _aspect(aspect), camera::camera(near, far) {
}

void perspective_camera::compute_projection_matrix() {
}

void perspective_camera::compute_visualization_matrix() {
}

