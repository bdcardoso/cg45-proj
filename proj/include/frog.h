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
    leg _leftleg, _rightleg;

public:
    void draw();
    void update(glut_time_t dt);
};

