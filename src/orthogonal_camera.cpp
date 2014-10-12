#include "orthogonal_camera.h"

orthogonal_camera::orthogonal_camera(
        GLdouble left,   GLdouble right,
        GLdouble bottom, GLdouble top,
        GLdouble near, GLdouble far):
    camera(near, far), _left(left), _right(right), _bottom(bottom), _top(top)  {
}

void orthogonal_camera::update(glut_time_t dt) {
    (void)dt;
}

void orthogonal_camera::compute_projection_matrix() {
    glOrtho(_left, _right, _bottom, _top, _near, _far);
}

void orthogonal_camera::compute_visualization_matrix() {
    vector3 eye = position();
    vector3 at(0.0, 0.0, 0.0);
    vector3 up = at.ext(eye);

    // FIXME
#if 0
    gluLookAt(eye.x(), eye.y(), eye.z(),
               at.x(),  at.y(),  at.z(),
               up.x(),  up.y(),  up.z());
#endif
}

