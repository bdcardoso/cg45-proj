#include "game_manager.h"

game_manager::game_manager() {
}

void game_manager::display() {
  glColor3f(0.4, 0.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.50, 0.25, 0.0);
    glVertex3f(0.50, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);
  glEnd();

#if 0
  glColor3f(1.0, 0.25, 0.25);
  glBegin(GL_POLYGON);
    glVertex3f(0.50, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.50, 0.75, 0.0);
  glEnd();
#endif
}

void game_manager::reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glMatrixMode(GL_VIEWPORT);
  glLoadIdentity();

  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

