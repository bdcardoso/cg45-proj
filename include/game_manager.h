#pragma once
#include "game_object.h"
#include "light_source.h"
#include "camera.h"
#include <memory>
#include <vector>

class game_manager {
private:
    std::vector<std::shared_ptr<game_object>> _game_objects;
    std::vector<std::shared_ptr<light_source>> _light_sources;
    std::vector<std::shared_ptr<camera>> _cameras;
    glut_time_t _last_time;
    GLdouble _spin, _tilt, _spin_speed, _tilt_speed;
    unsigned _current_camera;

    GLdouble WINDOW_WIDTH, WINDOW_HEIGHT, GAME_WIDTH, GAME_HEIGHT, GAME_DEPTH;

public:
    game_manager(int w, int h);

    void display();
    void reshape(int w, int h);
    void keyboard(unsigned char key, int x, int y);
    void keyboardUp(unsigned char key, int x, int y);
    void special(int key, int x, int y);
    void specialUp(int key, int x, int y);
    void timer();
    void idle();
    void update();
    void init();
};
