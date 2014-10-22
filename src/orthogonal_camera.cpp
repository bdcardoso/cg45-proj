#include "orthogonal_camera.h"
#include "game_manager.h"

orthogonal_camera::orthogonal_camera(GLdouble left, GLdouble right,
                                     GLdouble bottom, GLdouble top,
                                     GLdouble near, GLdouble far)
        : camera::camera(near, far),
          left_(left),
          right_(right),
          bottom_(bottom),
          top_(top) {}

void orthogonal_camera::reshape(int w, int h) {
    float xScale = float(w) / game_manager::instance()->window_width(),
          yScale = float(h) / game_manager::instance()->window_height(),
          scale = std::min(xScale, yScale);

    xScale /= scale;
    yScale /= scale;
    float gameWidth = game_manager::instance()->game_width() * xScale,
          gameHeight = game_manager::instance()->game_height() * yScale;

    left_ = -gameWidth;
    right_ = gameWidth;
    bottom_ = -gameHeight;
    top_ = gameHeight;
    near_ = -game_manager::instance()->game_depth();
    far_ = game_manager::instance()->game_depth();
}

void orthogonal_camera::compute_projection_matrix() {
    glOrtho(left_, right_, bottom_, top_, near_, far_);
}
