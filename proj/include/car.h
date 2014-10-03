#pragma once
#include "dynamic_object.h"

class car : public dynamic_object {
public:
    void draw();
    void update(glut_time_t dt);
};

