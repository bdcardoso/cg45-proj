#include "river.h"
#include "opengl.h"

void river::draw() {
  glColor3f(0.6, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
  glEnd();
}

