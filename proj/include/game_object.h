#pragma once
#include "entity.h"
#include "opengl.h"

class game_object : public entity {
public:
    game_object();

    virtual void draw() = 0;
    virtual void update(GLdouble dt) = 0;
};
