#pragma once
#include "dynamic_object.h"

class frog : public dynamic_object {
    // The frog's legs
    class leg : public dynamic_object {
    public:
        void draw();
        void update(glut_time_t dt);
    };

private:
    float _angle;
    leg _leftleg, _rightleg;

public:
    frog();

    void draw();
    void update(glut_time_t dt);
};
