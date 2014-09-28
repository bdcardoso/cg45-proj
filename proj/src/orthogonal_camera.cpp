#include "orthogonal_camera.h"
#include "vector3.h"
#include "opengl.h"


orthogonal_camera::orthogonal_camera(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) {
    _left = left;
    _right = right;
    _top = top;
    _bottom = bottom;

}
