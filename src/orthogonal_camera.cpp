#include "orthogonal_camera.h"
#include "game_manager.h"

orthogonal_camera::orthogonal_camera(GLdouble left, GLdouble right,
                                     GLdouble bottom, GLdouble top,
                                     GLdouble near, GLdouble far)
        : camera::camera(near, far),
          _left(left),
          _right(right),
          _bottom(bottom),
          _top(top) {}

void orthogonal_camera::reshape(int w, int h) {
    float xScale = float(w) / game_manager::instance()->window_width(),
          yScale = float(h) / game_manager::instance()->window_height(),
          scale = std::min(xScale, yScale);

    xScale /= scale;
    yScale /= scale;
    float gameWidth = game_manager::instance()->game_width() * xScale,
          gameHeight = game_manager::instance()->game_height() * yScale;

    _left   = -gameWidth;
    _right  =  gameWidth;
    _bottom = -gameHeight;
    _top    =  gameHeight;
    _near   = -game_manager::instance()->game_depth();
    _far    =  game_manager::instance()->game_depth();
}

void orthogonal_camera::compute_projection_matrix() {
    glOrtho(_left, _right, _bottom, _top, _near, _far);
}

void orthogonal_camera::compute_visualization_matrix() {
}
