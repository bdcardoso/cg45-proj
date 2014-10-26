#include "perspective_camera.h"
#include "game_manager.h"

perspective_camera::perspective_camera(GLdouble fovy, GLdouble aspect,
                                       GLdouble near, GLdouble far)
        : camera::camera(near, far), fovy_(fovy), aspect_(aspect) {}

void perspective_camera::reshape(int w, int h) {
    fovy_ = 90;
    aspect_ = float(w) / float(h);
    near_ = 1;
    far_ = 2 * game_manager::instance().game_depth();
}

void perspective_camera::compute_projection_matrix() {
    gluPerspective(fovy_, aspect_, near_, far_);
}
