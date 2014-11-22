#include "game_manager.h"
#include "bus.h"
#include "car.h"
#include "frog.h"
#include "orthogonal_camera.h"
#include "perspective_camera.h"
#include "river.h"
#include "road.h"
#include "timberlog.h"
#include "turtle.h"
#include "truck.h"
#include "tunnel.h"
#include <cassert>

constexpr auto FROG_LEVEL = 0.05, ROAD_LEVEL = 0.05, RIVER_LEVEL = 0.05,
               LINE_1 = -1.0, LINE_2 = -0.5, LINE_3 = 0.5, LINE_4 = 1.0,
               LINE_5 = 1.5, LINE_6 = -1.5;

void game_manager::init(int w, int h) {
    WINDOW_WIDTH = w;
    WINDOW_HEIGHT = h;

    last_time_ = glutGet(GLUT_ELAPSED_TIME);

    auto frog_ = std::make_shared<frog>();
    frog_->position() = vector3(0.0, FROG_LEVEL, 1.95);
    frog_->scale(0.1);
    game_objects_.push_back(frog_);
    collision_manager::instance().register_object(frog_);

    auto car1_ = std::make_shared<car>();
    car1_->position() = vector3(-1.2, ROAD_LEVEL, LINE_4);
    car1_->scale(0.1);
    car1_->speed().x() = 1.0;
    game_objects_.push_back(car1_);
    collision_manager::instance().register_object(car1_);

    for (int i = 0; i < 3; i++) {
        auto truck_ = std::make_shared<truck>();
        truck_->position() = vector3(-1.5 + i * 1.5, ROAD_LEVEL, LINE_3);
        truck_->scale(0.1);
        truck_->speed().x() = 0.5;
        game_objects_.push_back(truck_);
        collision_manager::instance().register_object(truck_);
    }

    auto bus1_ = std::make_shared<bus>();
    bus1_->position() = vector3(0.9, ROAD_LEVEL, LINE_5);
    bus1_->scale(0.1);
    bus1_->speed().x() = 1.5;
    game_objects_.push_back(bus1_);
    collision_manager::instance().register_object(bus1_);

    auto bus2_ = std::make_shared<bus>();
    bus2_->position() = vector3(-0.1, ROAD_LEVEL, LINE_4);
    bus2_->scale(0.1);
    bus2_->speed().x() = 1.0;
    game_objects_.push_back(bus2_);
    collision_manager::instance().register_object(bus2_);

    for (int i = 0; i < 2; i++) {
        auto log_ = std::make_shared<timberlog>();
        log_->position() = vector3(-0.6 + i * 2.0, RIVER_LEVEL, LINE_1);
        log_->scale(0.1);
        log_->speed().x() = 0.5;
        game_objects_.push_back(log_);
        collision_manager::instance().register_object(log_);

        auto log1_ = std::make_shared<timberlog>();
        log1_->position() = vector3(-1.1 + i * 1.9, RIVER_LEVEL, LINE_2);
        log1_->scale(0.1);
        log1_->speed().x() = 0.75;
        game_objects_.push_back(log1_);
        collision_manager::instance().register_object(log1_);
    }

    for (int i = 0; i < 4; i++) {
        auto turtle_ = std::make_shared<turtle>();
        turtle_->position() =
            vector3(-2.5 + i * 1.3, RIVER_LEVEL + 0.05, LINE_6);
        turtle_->scale(0.1);
        turtle_->speed().x() = 0.75;
        game_objects_.push_back(turtle_);
        collision_manager::instance().register_object(turtle_);
    }

    auto river_ = std::make_shared<river>();
    river_->position() = vector3(0.0, 0.0, LINE_1);
    game_objects_.push_back(river_);
    collision_manager::instance().register_object(river_);

    auto tunnel_ = std::make_shared<tunnel>();
    tunnel_->position() = vector3(0.0, 0.0, LINE_1);
    game_objects_.push_back(tunnel_);

    auto road_ = std::make_shared<road>();
    road_->position() = vector3(0.0, 0.0, LINE_4);
    game_objects_.push_back(road_);

    // INVALID CAMERAS: they will be set correctly on reshape
    // Camera 0: top view orthogonal camera
    cameras_.push_back(std::make_shared<orthogonal_camera>());
    cameras_.back()->eye().set(0.0, 0.0, 0.0);
    cameras_.back()->at().set(0.0, -1.0, 0.0);
    cameras_.back()->up().set(0.0, 0.0, -1.0);

    // Camera 1: top view perspective camera
    cameras_.push_back(std::make_shared<perspective_camera>());
    cameras_.back()->eye().set(0.0, 3.0, 2.0);
    cameras_.back()->at().set(0.0, 0.0, 0.0);
    cameras_.back()->up().set(0.0, 0.0, -1.0);

    // Camera 2: frog perspective camera
    cameras_.push_back(frog_->cam());

    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT0));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT1));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT2));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT3));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT4));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT5));
    light_sources_.push_back(std::make_shared<light_source>(GL_LIGHT6));
    light_sources_.push_back(frog_->headlight());

    auto light = light_sources_[0];
    light->ambient().set(0.2, 0.2, 0.2, 1.0);
    light->diffuse().set(0.3, 0.3, 0.3, 1.0);
    light->position().set(0.0, 5.0, 0.0, 1.0);
    light->turn_on();
    light->toggle_key() = 'n';

    for (size_t i : {1, 2, 3, 4, 5, 6}) {
        light = light_sources_[i];
        light->toggle_key() = 'c';
        light->diffuse().set(0.23, 0.23, 0.23, 1.0);
        light->turn_off();

        light->position().x() = i % 2 == 0 ? 2.0 : -2.0;
        light->direction().x() = -light->position().x() / 2;

        light->position().y() = 1.5;
        light->direction().y() = -light->position().y();

        light->position().z() = -2.0 + 2.0 * ((i - 1) / 2);
        light->direction().z() = -light->position().z() / 2;

        // make positional light
        light->position().w() = 1;
        light->cutoff() = 30;
        light->exponent() = 15;
    }
}

game_manager::game_manager()
        : current_camera_(2),
          spin_(0.0),
          tilt_(0.0),
          spin_speed_(0.0),
          tilt_speed_(0.0),
          GAME_WIDTH(2.5),
          GAME_HEIGHT(2),
          GAME_DEPTH(5),
          lighting_enabled_(true),
          paused_(false) {}

void game_manager::timer() { update(); }

void game_manager::display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    cameras_[current_camera_]->compute_visualization_matrix();

    glPushMatrix();

    glRotatef(tilt_, 1.0, 0.0, 0.0);
    glRotatef(spin_, 0.0, 1.0, 0.0);

    for (auto light : light_sources_) {
        light->draw();
    }

    for (auto obj : game_objects_) {
        glPushMatrix();

        auto pos = obj->position();
        auto scl = obj->scale();

        glTranslatef(pos.x(), pos.y(), pos.z());
        glScalef(scl.x(), scl.y(), scl.z());

        obj->draw();
        glPopMatrix();
    }

    glPopMatrix();
}

void game_manager::update() {
    auto currentTime = glutGet(GLUT_ELAPSED_TIME);
    auto dt = (currentTime - last_time_) / glut_time_t(1000);
    last_time_ = currentTime;

    spin_ += spin_speed_ * dt;
    tilt_ += tilt_speed_ * dt;

    if (!paused_) {
        for (auto obj : game_objects_) {
            obj->update(dt);
        }

        for (auto cam : cameras_) {
            cam->update(dt);
        }

        for (auto light : light_sources_) {
            light->update(dt);
        }
    }

    glutPostRedisplay();
}

void game_manager::reshape(int w, int h) {
    glViewport(0, 0, w, h);

    for (auto cam : cameras_) {
        cam->reshape(w, h);
    }

    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    cameras_[current_camera_]->compute_projection_matrix();
}

void game_manager::keyboard(unsigned char key, int x, int y) {
    (void)x, (void)y;

    for (auto obj : game_objects_) {
        obj->keydown(key);
    }

    for (auto light : light_sources_) {
        light->keydown(key);
    }
}

void game_manager::keyboardUp(unsigned char key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case '1':
    case '2':
    case '3':
        current_camera_ = key - '1';
        // HACK: We need to force reshape
        glutReshapeWindow(glutGet(GLUT_WINDOW_WIDTH),
                          glutGet(GLUT_WINDOW_HEIGHT));
        break;
    case 'l':
        if (lighting_enabled_)
            glDisable(GL_LIGHTING);
        else
            glEnable(GL_LIGHTING);
        lighting_enabled_ = !lighting_enabled_;
        break;
    case 's':
        paused_ = !paused_;
        break;
    default:
        break;
    }

    for (auto obj : game_objects_) {
        obj->keyup(key);
    }

    for (auto light : light_sources_) {
        light->keyup(key);
    }
}

void game_manager::special(int key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case GLUT_KEY_DOWN:
        tilt_speed_ = -30.0;
        break;
    case GLUT_KEY_UP:
        tilt_speed_ = 30.0;
        break;
    case GLUT_KEY_LEFT:
        spin_speed_ = -30.0;
        break;
    case GLUT_KEY_RIGHT:
        spin_speed_ = 30.0;
        break;
    default:
        break;
    }

    for (auto obj : game_objects_) {
        obj->specialdown(key);
    }

    for (auto light : light_sources_) {
        light->specialdown(key);
    }
}

void game_manager::specialUp(int key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case GLUT_KEY_HOME: {
        tilt_ = 0.0;
        spin_ = 0;
        break;
    }
    case GLUT_KEY_DOWN:
        tilt_speed_ = 0.0;
        break;
    case GLUT_KEY_UP:
        tilt_speed_ = 0.0;
        break;
    case GLUT_KEY_LEFT:
        spin_speed_ = 0.0;
        break;
    case GLUT_KEY_RIGHT:
        spin_speed_ = 0.0;
        break;
    default:
        break;
    }

    for (auto obj : game_objects_) {
        obj->specialup(key);
    }

    for (auto light : light_sources_) {
        light->specialup(key);
    }
}

GLdouble game_manager::game_width() const { return GAME_WIDTH; }
GLdouble game_manager::game_height() const { return GAME_HEIGHT; }
GLdouble game_manager::game_depth() const { return GAME_DEPTH; }
GLdouble game_manager::window_width() const { return WINDOW_WIDTH; }
GLdouble game_manager::window_height() const { return WINDOW_HEIGHT; }

const bounding_box &game_manager::game_object_bounds() const {
    // FIXME TODO XXX
    static bounding_box bb(-game_depth(), -0.5, -game_width(), game_depth(),
                           0.5, game_width());
    return bb;
}

const bounding_box &game_manager::frog_bounds() const {
    // FIXME TODO XXX
    static bounding_box bb(-1.85, -0.5, -1.90, 1.85, 0.5, 1.90);
    return bb;
}
