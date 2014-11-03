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

    unsigned current_camera_ = 2;

    GLdouble spin_ = 0, tilt_ = 0, spin_speed_ = 0, tilt_speed_ = 0;
    GLdouble WINDOW_WIDTH, WINDOW_HEIGHT, GAME_WIDTH, GAME_HEIGHT, GAME_DEPTH;

    bool lighting_enabled_ = true;

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

    const bounding_box &game_object_bounds() const;
    const bounding_box &frog_bounds() const;
};
