#include "game_manager.h"
#include "bus.h"
#include "car.h"
#include "frog.h"
#include "orthogonal_camera.h"
#include "river.h"
#include "road.h"
#include "timberlog.h"
#include "turtle.h"

game_manager::game_manager() : _spin(0.0), _tilt(90.0), _spin_speed(0.0), _tilt_speed(0.0), GAME_SIZE(2.5) {
    _lastTime = glutGet(GLUT_ELAPSED_TIME);

    auto _frog = std::make_shared<frog>();
    _frog->position(vector3( 0.0, 1.0, -1.0));
    auto _river = std::make_shared<river>();
    _river->position(vector3(0.0, 0.0, -1.0));
    auto _road = std::make_shared<road>();
    _road->position(vector3( 0.0, 0.0,  1.0));

    _game_objects.push_back(_frog);
    _game_objects.push_back(_river);
    _game_objects.push_back(_road);
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
                auto scl = obj->scale();
                glScalef(scl.x(), scl.y(), scl.z());
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

    _camera->update(dt);

    glutPostRedisplay();
}

void game_manager::reshape(int w, int h) {
    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat shininess[] = { 1.0 };
    GLfloat light_pos[]  = { 100.0, 100.0, 100.0, 0.0 };
    GLfloat global_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    
    // TODO: extract
    float ySize = h / float(w) * GAME_SIZE;
    _camera = std::make_shared<orthogonal_camera>(-GAME_SIZE, GAME_SIZE, -ySize, ySize, -GAME_SIZE*5, GAME_SIZE*5);
    _camera->position(0.0, 0.0, 0.0);


    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glViewport(0, 0, w, h);

    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    _camera->compute_projection_matrix();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    _camera->compute_visualization_matrix();

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

