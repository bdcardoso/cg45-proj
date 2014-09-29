#include "game_manager.h"
#include "opengl.h"

game_manager *manager = nullptr;

void display() {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glClear(GL_COLOR_BUFFER_BIT);

  manager->display();

  glFlush();
  glutSwapBuffers();
}

void reshape(int w, int h) {
  manager->reshape(w, h);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(-1, -1);
  glutInitWindowSize(640, 480);
  glutCreateWindow("CG45 - Lab 1 - Tarefa 3");

  manager = new game_manager;

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  glutMainLoop();

  delete manager;

  return 0;
}

