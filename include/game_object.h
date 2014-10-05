#pragma once
#include "entity.h"

class game_object : public entity {
public:
    game_object();

    virtual void draw() = 0;
    virtual void update(glut_time_t dt) = 0;
};

