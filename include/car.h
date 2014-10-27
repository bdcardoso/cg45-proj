#pragma once
#include "dynamic_object.h"

class car : public dynamic_object {
public:
    car();

    void draw() override;
    void update(glut_time_t dt) override;
};
