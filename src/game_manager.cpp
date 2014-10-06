#include "game_manager.h"
#include "car.h"
#include "frog.h"
#include "river.h"

game_manager::game_manager() : _angle(0.0) {
    _lastTime = glutGet(GLUT_ELAPSED_TIME);
    
    auto _frog = std::make_shared<frog>();
    _frog->position(vector3(5.0, 0.0, 0.0));
    auto _car = std::make_shared<car>();
    _car->position(vector3(0.0, 0.0, 5.0));
    auto _river = std::make_shared<river>();
    _river->position(vector3(-5.0, 0.0, 0.0));

    _game_objects.push_back(_frog);
    _game_objects.push_back(_car);
    _game_objects.push_back(_river);
}

void game_manager::timer() {
    update();
}

void game_manager::display() {
    glPushMatrix();
        glRotatef(30, 1.0, 0.0, 0.0);
        glRotatef(_angle, 0.0, 1.0, 0.0);

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
    _angle += 5.0 / (1000.0 / dt);

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
	for (auto obj : _game_objects) {
		obj->keydown(key);
	}	
}

void game_manager::keyboardUp(unsigned char key, int x, int y) {
	for (auto obj : _game_objects) {
		obj->keyup(key);
	}	
}
