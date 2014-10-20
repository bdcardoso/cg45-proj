#pragma once
#include "dynamic_object.h"

class truck : public dynamic_object {
public:
    void draw() override;
    void update(glut_time_t dt) override;
};
