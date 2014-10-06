#pragma once
#include "entity.h"

class game_object : public entity {
public:
    game_object();

    virtual void draw() {};
    virtual void keydown(unsigned char key) {};
    virtual void keyup(unsigned char key) {};
    virtual void update(glut_time_t dt) {};
};

