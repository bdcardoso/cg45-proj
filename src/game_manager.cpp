#include "game_manager.h"
#include "car.h"
#include "bus.h"
#include "frog.h"
#include "turtle.h"
#include "river.h"
#include "road.h"
#include "timberlog.h"

game_manager::game_manager() : _spin(0.0), _tilt(90.0), _spin_speed(0.0), _tilt_speed(0.0) {
    _lastTime = glutGet(GLUT_ELAPSED_TIME);

    auto _frog = std::make_shared<frog>();
    _frog->position(vector3(5.0, 0.0, 0.0));
    auto _turtle = std::make_shared<turtle>();
    _turtle->position(vector3(10.0, 0.0, 0.0));
    auto _car = std::make_shared<car>();
    _car->position(vector3(0.0, 0.0, 5.0));
    auto _bus = std::make_shared<bus>();
    _bus->position(vector3(0.0, 0.0, 10.0));
    auto _river = std::make_shared<river>();
    _river->position(vector3(0.0, 0.0, -10.0));
    auto _road = std::make_shared<road>();
    _road->position(vector3(0.0, 0.0, -5.0));
    auto _timberlog = std::make_shared<timberlog>();
    _timberlog->position(vector3(-5.0, 0.0, 0.0));

    _game_objects.push_back(_frog);
    _game_objects.push_back(_turtle);
    _game_objects.push_back(_car);
    _game_objects.push_back(_bus);
    _game_objects.push_back(_river);
    _game_objects.push_back(_road);
    _game_objects.push_back(_timberlog);
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
                obj->draw();
            glPopMatrix();
        }

    glPopMatrix();
}

void game_manager::update() {
    auto currentTime = glutGet(GLUT_ELAPSED_TIME);
    auto dt = currentTime - _lastTime;

    for (auto obj : _game_objects) {
        obj->update(dt);
    }

    _lastTime = currentTime;
    _spin += _spin_speed / (1000.0 / dt);
    _tilt += _tilt_speed / (1000.0 / dt);

    glutPostRedisplay();
}

void game_manager::reshape(int w, int h) {
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat shininess[] = { 1.0 };
    GLfloat light_pos[]  = { 100.0, 100.0, 100.0, 0.0 };
    GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };

    glViewport(0, 0, w, h);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);


    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // TODO: extract
    float gameSize = 10.f;
    float ySize = h / float(w) * gameSize;
    glOrtho(-gameSize, gameSize, -ySize, ySize, -gameSize*5, gameSize*5);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}

void game_manager::keyboard(unsigned char key, int x, int y) {
    (void)x, (void)y;

    for (auto obj : _game_objects) {
	obj->keydown(key);
    }	
}

void game_manager::keyboardUp(unsigned char key, int x, int y) {
    (void)x, (void)y;
    
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
            _tilt = 90.0;
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

