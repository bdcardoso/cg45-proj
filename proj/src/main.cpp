#include "game_manager.h"
#include "opengl.h"

game_manager *manager = nullptr;
constexpr int FPS = 30;

void init(void);

void display() {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  manager->display();

  glFlush();
  glutSwapBuffers();
}

void reshape(int w, int h) {
  manager->reshape(w, h);
}

void timer(int value) {
    manager->timer();

    (void)value;

    glutTimerFunc(1000 / FPS, timer, 0);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(-1, -1);
    glutInitWindowSize(640, 480);
    glutCreateWindow("CG45 - Lab 1 - Tarefa 3");

    glEnable(GL_DEPTH_TEST);

    manager = new game_manager;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000 / FPS, timer, 0);

    glutMainLoop();

    delete manager;

    return 0;
}

