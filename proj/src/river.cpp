#include "river.h"

river::river() {}

void river::draw() {
  glColor3f(0.6, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
  glEnd();

  glColor3f(0.0, 0.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.2,0.0,0.0);
    glVertex3f(0.2,1.0,0.0);
    glVertex3f(0.8,1.0,0.0);
    glVertex3f(0.8,0.0,0.0);
  glEnd();
}

void river::update(GLdouble dt) {

}

