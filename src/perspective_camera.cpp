#include "perspective_camera.h"
#include "vector3.h"
#include "opengl.h"


perspective_camera::perspective_camera(GLdouble fovy, GLdouble aspect) {
    //ainda recebe o znear e o zfar
    _fovy = fovy;
    _aspect = aspect;
}

void perspective_camera::update(){
//TODO

}

void perspective_camera::compute_projection_matrix() {
    //TODO
}

void perspective_camera::compute_visualization_matrix() {
    //TODO
}

