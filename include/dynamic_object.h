#pragma once
#include "game_object.h"

class dynamic_object : public game_object {
protected:
    vector3 speed_;

public:
    typedef vector3::scalar_t scalar_t;

    dynamic_object();

    void update(glut_time_t dt);

    vector3 &speed();
    void speed(const vector3 &speed);
    void speed(scalar_t x, scalar_t y, scalar_t z);
};
