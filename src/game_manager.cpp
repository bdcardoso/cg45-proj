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
}

game_manager::game_manager()
        : current_camera_(0),
          spin_(0.0),
          tilt_(0.0),
          spin_speed_(0.0),
          tilt_speed_(0.0),
          GAME_WIDTH(2.5),
          GAME_HEIGHT(2),
          GAME_DEPTH(5) {

    last_time_ = glutGet(GLUT_ELAPSED_TIME);

    auto frog_ = std::make_shared<frog>();
    frog_->position(vector3(0.0, FROG_LEVEL, 1.95));
    frog_->scale(0.1);

    auto car1_ = std::make_shared<car>();
    car1_->position(vector3(-1.2, ROAD_LEVEL, LINE_4));
    car1_->scale(0.1);
    car1_->speed(1.5, 0, 0);

    auto truck1_ = std::make_shared<truck>();
    truck1_->position(vector3(-1.5, ROAD_LEVEL, LINE_3));
    truck1_->scale(0.1);
    truck1_->speed(2.5, 0, 0);

    auto truck2_ = std::make_shared<truck>();
    truck2_->position(vector3(0.0, ROAD_LEVEL, LINE_3));
    truck2_->scale(0.1);
    truck2_->speed(2.5, 0, 0);

    auto truck3_ = std::make_shared<truck>();
    truck3_->position(vector3(1.5, ROAD_LEVEL, LINE_3));
    truck3_->scale(0.1);
    truck3_->speed(2.5, 0, 0);

    auto bus1_ = std::make_shared<bus>();
    bus1_->position(vector3(0.9, ROAD_LEVEL, LINE_5));
    bus1_->scale(0.1);
    bus1_->speed(1.5, 0, 0);

    auto bus2_ = std::make_shared<bus>();
    bus2_->position(vector3(-0.1, ROAD_LEVEL, LINE_4));
    bus2_->scale(0.1);
    bus2_->speed(1.5, 0, 0);

    auto log1_ = std::make_shared<timberlog>();
    log1_->position(vector3(-0.6, RIVER_LEVEL, LINE_1));
    log1_->scale(0.1);
    log1_->speed(4.5, 0, 0);

    auto log2_ = std::make_shared<timberlog>();
    log2_->position(vector3(-1.4, RIVER_LEVEL, LINE_2));
    log2_->scale(0.1);
    log2_->speed(4.0, 0, 0);

    auto log3_ = std::make_shared<timberlog>();
    log3_->position(vector3(0.8, RIVER_LEVEL, LINE_2));
    log3_->scale(0.1);
    log3_->speed(4.0, 0, 0);

    auto log4_ = std::make_shared<timberlog>();
    log4_->position(vector3(1.4, RIVER_LEVEL, LINE_1));
    log4_->scale(0.1);
    log4_->speed(4.5, 0, 0);

    auto turtle1_ = std::make_shared<turtle>();
    turtle1_->position(vector3(-2.5, RIVER_LEVEL + 0.05, LINE_6));
    turtle1_->scale(0.1);
    turtle1_->speed(2, 0, 0);

    auto turtle2_ = std::make_shared<turtle>();
    turtle2_->position(vector3(-1.25, RIVER_LEVEL + 0.05, LINE_6));
    turtle2_->scale(0.1);
    turtle2_->speed(2, 0, 0);

    auto turtle3_ = std::make_shared<turtle>();
    turtle3_->position(vector3(1.25, RIVER_LEVEL + 0.05, LINE_6));
    turtle3_->scale(0.1);
    turtle3_->speed(2, 0, 0);

    auto turtle4_ = std::make_shared<turtle>();
    turtle4_->position(vector3(2.5, RIVER_LEVEL + 0.05, LINE_6));
    turtle4_->scale(0.1);
    turtle4_->speed(2, 0, 0);

    auto river_ = std::make_shared<river>();
    river_->position(vector3(0.0, 0.0, LINE_1));

    auto tunnel_ = std::make_shared<tunnel>();
    tunnel_->position(vector3(0.0, 0.0, LINE_1));

    auto road_ = std::make_shared<road>();
    road_->position(vector3(0.0, 0.0, LINE_4));

    game_objects_.push_back(frog_);

    game_objects_.push_back(river_);
    game_objects_.push_back(tunnel_);
    game_objects_.push_back(log1_);
    game_objects_.push_back(log2_);
    game_objects_.push_back(log3_);
    game_objects_.push_back(log4_);
    game_objects_.push_back(turtle1_);
    game_objects_.push_back(turtle2_);
    game_objects_.push_back(turtle3_);
    game_objects_.push_back(turtle4_);
    game_objects_.push_back(road_);
    game_objects_.push_back(car1_);
    game_objects_.push_back(truck1_);
    game_objects_.push_back(truck2_);
    game_objects_.push_back(truck3_);
    game_objects_.push_back(bus1_);
    game_objects_.push_back(bus2_);

    colman_.register_object(frog_);
    colman_.register_object(log1_);
    colman_.register_object(log2_);
    colman_.register_object(log3_);
    colman_.register_object(log3_);
    colman_.register_object(turtle1_);
    colman_.register_object(turtle2_);
    colman_.register_object(turtle3_);
    colman_.register_object(turtle3_);
    colman_.register_object(car1_);
    colman_.register_object(truck1_);
    colman_.register_object(truck2_);
    colman_.register_object(truck3_);
    colman_.register_object(bus1_);
    colman_.register_object(bus2_);

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
}

void game_manager::timer() { update(); }

void game_manager::display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    cameras_[current_camera_]->compute_visualization_matrix();

    glPushMatrix();
    glRotatef(tilt_, 1.0, 0.0, 0.0);
    glRotatef(spin_, 0.0, 1.0, 0.0);

    // Axis helpers
    glLineWidth(1.0);
    glColor3ub(255, 0, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(100, 0, 0);
    glEnd();
    glColor3ub(0, 255, 0);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 100, 0);
    glEnd();
    glColor3ub(0, 0, 255);
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 100);
    glEnd();

    for (auto obj : game_objects_) {
        glPushMatrix();
        auto pos = obj->position();
        glTranslatef(pos.x(), pos.y(), pos.z());
        auto scl = obj->scale();
        glScalef(scl.x(), scl.y(), scl.z());

        obj->draw();
        glPopMatrix();
    }

    glPopMatrix();
}

void game_manager::update() {
    auto currentTime = glutGet(GLUT_ELAPSED_TIME);
    auto dt = (currentTime - last_time_) / glut_time_t(1000);

    for (auto obj : game_objects_) {
        obj->update(dt);
    }

    last_time_ = currentTime;
    spin_ += spin_speed_ * dt;
    tilt_ += tilt_speed_ * dt;

    for (auto cam : cameras_) {
        cam->update(dt);
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
    default:
        break;
    }

    for (auto obj : game_objects_) {
        obj->keyup(key);
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
}

GLdouble game_manager::game_width() const { return GAME_WIDTH; }
GLdouble game_manager::game_height() const { return GAME_HEIGHT; }
GLdouble game_manager::game_depth() const { return GAME_DEPTH; }
GLdouble game_manager::window_width() const { return WINDOW_WIDTH; }
GLdouble game_manager::window_height() const { return WINDOW_HEIGHT; }
