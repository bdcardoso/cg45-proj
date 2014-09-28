#pragma once

#include "opengl.h"
#include "vector3.h"


class camera {
private:

    GameObject _game_objects;
    LightSource _light_sources;
    Camera _cameras;

public:
    game_manager();

    void display();

    void reshape(GLsizei w, GLsizei h);

    void keypressed();

    void ontimer();

    void idle();

    void update();

    void init();

};
