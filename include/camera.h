#pragma once
#include "dynamic_object.h"

class camera : public dynamic_object {
protected:
    vector3 up_, at_;
    GLdouble near_, far_;

    camera(GLdouble near = 0.0, GLdouble far = 1.0);

public:
    vector3 &eye();
    void eye(const vector3 &e);

    vector3 &at();
    void at(const vector3 &e);

    vector3 &up();
    void up(const vector3 &e);

    virtual void reshape(int w, int h) = 0;
    virtual void compute_projection_matrix() = 0;
    virtual void compute_visualization_matrix() = 0;
};
