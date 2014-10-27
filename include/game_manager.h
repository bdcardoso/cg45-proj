#pragma once
#include "game_object.h"
#include "camera.h"
#include "collision_manager.h"
#include "light_source.h"
#include "singleton.h"
#include <memory>
#include <vector>

class game_manager : public singleton<game_manager> {
private:
    std::vector<std::shared_ptr<game_object>> game_objects_;
    std::vector<std::shared_ptr<light_source>> light_sources_;
    std::vector<std::shared_ptr<camera>> cameras_;

    glut_time_t last_time_;

    unsigned current_camera_;

    GLdouble spin_, tilt_, spin_speed_, tilt_speed_;
    GLdouble WINDOW_WIDTH, WINDOW_HEIGHT, GAME_WIDTH, GAME_HEIGHT, GAME_DEPTH;

    friend class singleton;
    game_manager();

public:
    void init(int w, int h);

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

    // CONSTANTS
    GLdouble window_width() const;
    GLdouble window_height() const;
    GLdouble game_width() const;
    GLdouble game_height() const;
    GLdouble game_depth() const;
};
