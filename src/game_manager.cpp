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

constexpr auto FROG_LEVEL = 0.05, ROAD_LEVEL = 0.05, RIVER_LEVEL = 0.05,
               LINE_1=-1.0, LINE_2=-0.5, LINE_3=0.5,
               LINE_4=1.0, LINE_5=1.5, LINE_6=-1.5;

game_manager::game_manager(int w, int h)
        : _spin(0.0),
          _tilt(0.0),
          _spin_speed(0.0),
          _tilt_speed(0.0),
          _current_camera(0),
          WINDOW_WIDTH(w),
          WINDOW_HEIGHT(h),
          GAME_WIDTH(2.5),
          GAME_HEIGHT(2),
          GAME_DEPTH(5) {

    _last_time = glutGet(GLUT_ELAPSED_TIME);

    auto _frog = std::make_shared<frog>();
    _frog->position(vector3(0.0, FROG_LEVEL, 1.95));
    _frog->scale(0.1);

    auto _car1 = std::make_shared<car>();
    _car1->position(vector3(-1.2, ROAD_LEVEL, LINE_4));
    _car1->scale(0.1);
    _car1->speed(1.5, 0, 0);

    auto _truck1 = std::make_shared<truck>();
    _truck1->position(vector3(-1.5, ROAD_LEVEL, LINE_3));
    _truck1->scale(0.1);
    _truck1->speed(2.5, 0, 0);
    
    auto _truck2 = std::make_shared<truck>();
    _truck2->position(vector3(0.0, ROAD_LEVEL, LINE_3));
    _truck2->scale(0.1);
    _truck2->speed(2.5, 0, 0);
    
    auto _truck3 = std::make_shared<truck>();
    _truck3->position(vector3(1.5, ROAD_LEVEL, LINE_3));
    _truck3->scale(0.1);
    _truck3->speed(2.5, 0, 0);        

    auto _bus1 = std::make_shared<bus>();
    _bus1->position(vector3(0.9, ROAD_LEVEL, LINE_5));
    _bus1->scale(0.1);
    _bus1->speed(1.5, 0, 0);
    
    auto _bus2 = std::make_shared<bus>();
    _bus2->position(vector3(-0.1, ROAD_LEVEL, LINE_4));
    _bus2->scale(0.1);
    _bus2->speed(1.5, 0, 0);

    auto _log1 = std::make_shared<timberlog>();
    _log1->position(vector3(-0.6, RIVER_LEVEL, LINE_1));
    _log1->scale(0.1);
    _log1->speed(4.5, 0, 0);

    auto _log2 = std::make_shared<timberlog>();
    _log2->position(vector3(-1.4, RIVER_LEVEL, LINE_2));
    _log2->scale(0.1);
    _log2->speed(4.0, 0, 0);

    auto _log3 = std::make_shared<timberlog>();
    _log3->position(vector3(0.8, RIVER_LEVEL, LINE_2));
    _log3->scale(0.1);
    _log3->speed(4.0, 0, 0);
    
    auto _log4 = std::make_shared<timberlog>();
    _log4->position(vector3(1.4, RIVER_LEVEL, LINE_1));
    _log4->scale(0.1);
    _log4->speed(4.5, 0, 0);    

    auto _turtle1 = std::make_shared<turtle>();
    _turtle1->position(vector3(-2.5, RIVER_LEVEL + 0.05, LINE_6));
    _turtle1->scale(0.1);
    _turtle1->speed(2, 0, 0);

    auto _turtle2 = std::make_shared<turtle>();
    _turtle2->position(vector3(-1.25, RIVER_LEVEL + 0.05, LINE_6));
    _turtle2->scale(0.1);
    _turtle2->speed(2, 0, 0);

    auto _turtle3 = std::make_shared<turtle>();
    _turtle3->position(vector3(1.25, RIVER_LEVEL + 0.05, LINE_6));
    _turtle3->scale(0.1);
    _turtle3->speed(2, 0, 0);

    auto _turtle4 = std::make_shared<turtle>();
    _turtle4->position(vector3(2.5, RIVER_LEVEL + 0.05, LINE_6));
    _turtle4->scale(0.1);
    _turtle4->speed(2, 0, 0);

    auto _river = std::make_shared<river>();
    _river->position(vector3(0.0, 0.0, LINE_1));

    auto _tunnel = std::make_shared<tunnel>();
    _tunnel->position(vector3(0.0, 0.0, LINE_1));

    auto _road = std::make_shared<road>();
    _road->position(vector3(0.0, 0.0, LINE_4));

    _game_objects.push_back(_frog);
    _game_objects.push_back(_river);
    _game_objects.push_back(_tunnel);
    _game_objects.push_back(_log1);
    _game_objects.push_back(_log2);
    _game_objects.push_back(_log3);
    _game_objects.push_back(_log4);
    _game_objects.push_back(_turtle1);
    _game_objects.push_back(_turtle2);
    _game_objects.push_back(_turtle3);
    _game_objects.push_back(_turtle4);
    _game_objects.push_back(_road);
    _game_objects.push_back(_car1);
    _game_objects.push_back(_truck1);
    _game_objects.push_back(_truck2);
    _game_objects.push_back(_truck3);    
    _game_objects.push_back(_bus1);
    _game_objects.push_back(_bus2);

    // INVALID CAMERAS: they will be set correctly on reshape
    // Camera 0: top view orthogonal camera
    _cameras.push_back(std::make_shared<orthogonal_camera>(0, 0, 0, 0, 0, 0));
    // Camera 1: top view perspective camera
    _cameras.push_back(std::make_shared<perspective_camera>(0, 0, 0, 0));
    // Camera 2: frog perspective camera
    _cameras.push_back(std::make_shared<perspective_camera>(0, 0, 0, 0));
}

void game_manager::timer() { update(); }

void game_manager::display() {
    glPushMatrix();
    glRotatef(_tilt, 1.0, 0.0, 0.0);
    glRotatef(_spin, 0.0, 1.0, 0.0);

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

    for (auto obj : _game_objects) {
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
    auto dt = (currentTime - _last_time) / glut_time_t(1000);

    for (auto obj : _game_objects) {
        obj->update(dt);
    }

    _last_time = currentTime;
    _spin += _spin_speed * dt;
    _tilt += _tilt_speed * dt;

    for (auto cam : _cameras) {
        cam->update(dt);
    }

    glutPostRedisplay();
}

void game_manager::reshape(int w, int h) {
    glViewport(0, 0, w, h);

    float xScale = float(w) / WINDOW_WIDTH, yScale = float(h) / WINDOW_HEIGHT,
          scale = std::min(xScale, yScale);

    xScale /= scale;
    yScale /= scale;
    float gameWidth = GAME_WIDTH * xScale, gameHeight = GAME_HEIGHT * yScale,
          fovy = 90 / yScale;

    _cameras[0] = std::make_shared<orthogonal_camera>(-gameWidth, gameWidth,
                                                      -gameHeight, gameHeight,
                                                      -GAME_DEPTH, GAME_DEPTH);
    _cameras[0]->position(0.0, 0.0, 0.0);
    _cameras[1] = std::make_shared<perspective_camera>(fovy, xScale, 0.1, 10);
    _cameras[1]->position(0.0, 0.0, 0.0);

    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    _cameras[_current_camera]->compute_projection_matrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    _cameras[_current_camera]->compute_visualization_matrix();
}

void game_manager::keyboard(unsigned char key, int x, int y) {
    (void)x, (void)y;

    for (auto obj : _game_objects) {
        obj->keydown(key);
    }
}

void game_manager::keyboardUp(unsigned char key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case '1':
    case '2':
    case '3':
        _current_camera = key - '1';
        // HACK: We need to force reshape
        glutReshapeWindow(glutGet(GLUT_WINDOW_WIDTH),
                          glutGet(GLUT_WINDOW_HEIGHT));
        break;
    default:
        break;
    }

    for (auto obj : _game_objects) {
        obj->keyup(key);
    }
}

void game_manager::special(int key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case GLUT_KEY_DOWN:
        _tilt_speed = -30.0;
        break;
    case GLUT_KEY_UP:
        _tilt_speed = 30.0;
        break;
    case GLUT_KEY_LEFT:
        _spin_speed = -30.0;
        break;
    case GLUT_KEY_RIGHT:
        _spin_speed = 30.0;
        break;
    default:
        break;
    }

    for (auto obj : _game_objects) {
        obj->specialdown(key);
    }
}

void game_manager::specialUp(int key, int x, int y) {
    (void)x, (void)y;

    switch (key) {
    case GLUT_KEY_HOME: {
        _tilt = 0.0;
        _spin = 0;
        break;
    }
    case GLUT_KEY_DOWN:
        _tilt_speed = 0.0;
        break;
    case GLUT_KEY_UP:
        _tilt_speed = 0.0;
        break;
    case GLUT_KEY_LEFT:
        _spin_speed = 0.0;
        break;
    case GLUT_KEY_RIGHT:
        _spin_speed = 0.0;
        break;
    default:
        break;
    }

    for (auto obj : _game_objects) {
        obj->specialup(key);
    }
}
