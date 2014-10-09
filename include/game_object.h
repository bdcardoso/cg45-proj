#pragma once
#include "entity.h"

class game_object : public entity {
public:
    game_object();

    virtual void draw() {};
    virtual void keydown(unsigned char key) { (void)key; };
    virtual void keyup(unsigned char key) { (void)key; };
    virtual void specialdown(int key) { (void)key; };
    virtual void specialup(int key) { (void)key; };
    virtual void update(glut_time_t dt) { (void)dt; };
};

