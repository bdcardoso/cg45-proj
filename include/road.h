#pragma once
#include "static_object.h"

class road : public static_object {
public:
    road();

    void draw() override;
    void update(glut_time_t dt) override;
};

