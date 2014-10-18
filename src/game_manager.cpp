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

constexpr auto FROG_LEVEL =   0.05,
               ROAD_LEVEL =   0.05,
               RIVER_LEVEL =  0.05;

game_manager::game_manager(int w, int h) :
        _spin(0.0), _tilt(0.0), _spin_speed(0.0), _tilt_speed(0.0),
        _current_camera(0), WINDOW_WIDTH(w), WINDOW_HEIGHT(h), GAME_WIDTH(2.5), GAME_HEIGHT(2), GAME_DEPTH(5) {

    _last_time = glutGet(GLUT_ELAPSED_TIME);

    auto _frog = std::make_shared<frog>();
    _frog->position(vector3( 0.0, FROG_LEVEL, 1.95));
    _frog->scale(0.1);


    auto _car1 = std::make_shared<car>();
    _car1->position(vector3(-1.2, ROAD_LEVEL,  1.0));
    _car1->scale(0.1);
    _car1->speed(1.5, 0, 0);

    auto _truck = std::make_shared<truck>();
    _truck->position(vector3( 1.3, ROAD_LEVEL,  0.5));
    _truck->scale(0.1);
    _truck->speed(2, 0, 0);


    auto _bus = std::make_shared<bus>();
    _bus->position(vector3( 0.9, ROAD_LEVEL,  1.5));
    _bus->scale(0.1);
    _bus->speed(1, 0, 0);

    auto _log1 = std::make_shared<timberlog>();
    _log1->position(vector3(-0.6, RIVER_LEVEL, -1.0));
    _log1->scale(0.1);
    _log1->speed(5.5, 0, 0);    

    auto _log2 = std::make_shared<timberlog>();
    _log2->position(vector3(-0.0, RIVER_LEVEL, -0.5));
    _log2->scale(0.1);
    _log2->speed(4, 0, 0);    
    
    auto _log3 = std::make_shared<timberlog>();
    _log3->position(vector3(-0.8, RIVER_LEVEL, -0.5));
    _log3->scale(0.1);
    _log3->speed(1, 0, 0); 

    auto _turtle1 = std::make_shared<turtle>();
    _turtle1->position(vector3( -1.9, RIVER_LEVEL+0.05, -1.5));
    _turtle1->scale(0.1);
    _turtle1->speed(1, 0, 0);    
    
    auto _turtle2 = std::make_shared<turtle>();
    _turtle2->position(vector3( -1.6, RIVER_LEVEL+0.05, -1.5));
    _turtle2->scale(0.1);
    _turtle2->speed(1, 0, 0); 
    
    auto _turtle3 = std::make_shared<turtle>();
    _turtle3->position(vector3( -1.3, RIVER_LEVEL+0.05, -1.5));
    _turtle3->scale(0.1);
    _turtle3->speed(1, 0, 0); 
    
    auto _turtle4 = std::make_shared<turtle>();
    _turtle4->position(vector3( -1, RIVER_LEVEL+0.05, -1.5));
    _turtle4->scale(0.1);
    _turtle4->speed(1, 0, 0); 
    
    auto _turtle5 = std::make_shared<turtle>();
    _turtle5->position(vector3( -0.7, RIVER_LEVEL+0.05, -1.5));
    _turtle5->scale(0.1);
    _turtle5->speed(1, 0, 0); 
    
    auto _turtle6 = std::make_shared<turtle>();
    _turtle6->position(vector3( 0.4, RIVER_LEVEL+0.05, -1.5));
    _turtle6->scale(0.1);
    _turtle6->speed(1, 0, 0); 
    
    auto _turtle7 = std::make_shared<turtle>();
    _turtle7->position(vector3( 0.0, RIVER_LEVEL+0.05, -1.5));
    _turtle7->scale(0.1);
    _turtle7->speed(1, 0, 0);    
    
    auto _turtle8 = std::make_shared<turtle>();
    _turtle8->position(vector3( -0.4, RIVER_LEVEL+0.05, -1.5));
    _turtle8->scale(0.1);
    _turtle8->speed(1, 0, 0); 
    
    auto _turtle9 = std::make_shared<turtle>();
    _turtle9->position(vector3( -0.8, RIVER_LEVEL+0.05, -1.5));
    _turtle9->scale(0.1);
    _turtle9->speed(1, 0, 0); 
    
    auto _turtle10 = std::make_shared<turtle>();
    _turtle10->position(vector3( -1.2, RIVER_LEVEL+0.05, -1.5));
    _turtle10->scale(0.1);
    _turtle10->speed(1, 0, 0); 
    
    auto _turtle11 = std::make_shared<turtle>();
    _turtle11->position(vector3( -1.55, RIVER_LEVEL+0.05, -1.5));
    _turtle11->scale(0.1);
    _turtle11->speed(1, 0, 0); 
    
    auto _turtle12 = std::make_shared<turtle>();
    _turtle12->position(vector3( -1.95, RIVER_LEVEL+0.05, -1.5));
    _turtle12->scale(0.1);
    _turtle12->speed(1, 0, 0); 
    

    auto _river = std::make_shared<river>();
    _river->position(vector3(0.0, 0.0, -1.0));
    
    auto _tunnel = std::make_shared<tunnel>();
    _tunnel->position(vector3(0.0, 0.0, -1.0));

    auto _road = std::make_shared<road>();
    _road->position(vector3( 0.0, 0.0,  1.0));

    _game_objects.push_back(_frog);
    _game_objects.push_back(_river);
    _game_objects.push_back(_tunnel);
    _game_objects.push_back(_log1);
    _game_objects.push_back(_log2);
    _game_objects.push_back(_log3);
    _game_objects.push_back(_turtle1);
    _game_objects.push_back(_turtle2);
    _game_objects.push_back(_turtle3);
    _game_objects.push_back(_turtle4);
    _game_objects.push_back(_turtle5);
    _game_objects.push_back(_turtle6);
    _game_objects.push_back(_turtle7);
    _game_objects.push_back(_turtle8);
    _game_objects.push_back(_turtle9);
    _game_objects.push_back(_turtle10);
    _game_objects.push_back(_turtle11);
    _game_objects.push_back(_turtle11);

    _game_objects.push_back(_road);
    _game_objects.push_back(_car1);
    _game_objects.push_back(_truck);
    _game_objects.push_back(_bus);

    // INVALID CAMERAS: they will be set correctly on reshape
    // Camera 0: top view orthogonal camera
    _cameras.push_back(std::make_shared<orthogonal_camera>(0,0,0,0,0,0));
    // Camera 1: top view perspective camera
    _cameras.push_back(std::make_shared<perspective_camera>(0,0,0,0));
    // Camera 2: frog perspective camera
    _cameras.push_back(std::make_shared<perspective_camera>(0,0,0,0));
}

void game_manager::timer() {
    update();
}

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

    float xScale = float(w) / WINDOW_WIDTH,
          yScale = float(h) / WINDOW_HEIGHT,
          scale  = std::min(xScale, yScale);

    xScale /= scale;
    yScale /= scale;
    float gameWidth  = GAME_WIDTH  * xScale,
          gameHeight = GAME_HEIGHT * yScale,
          fovy       = 90 / yScale;

    _cameras[0] = std::make_shared<orthogonal_camera>(-gameWidth,  gameWidth, -gameHeight, gameHeight, -GAME_DEPTH, GAME_DEPTH);
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
        glutReshapeWindow(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
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
        _spin_speed =  30.0;
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

