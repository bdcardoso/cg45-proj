#pragma once
#include "static_object.h"

class river : public static_object {
public:
    river();

    void draw();
    void update(glut_time_t dt) override;
};
