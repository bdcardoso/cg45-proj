#pragma once

#include "opengl.h"



class game_object {

public:

    game_object();

    void draw();
    void update(GLdouble delta_t){

    _delta_t = delta_t;
    }

}
