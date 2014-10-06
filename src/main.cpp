#include "game_manager.h"
#include "opengl.h"

game_manager *manager = nullptr;
constexpr int FPS = 60;

void init(void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void display() {
  glClearColor(0.f, 0.f, 0.f, 0.f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();

  manager->display();

  glPopMatrix();

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

void keyboard(unsigned char key, int x, int y) {
	manager->keyboard(key, x, y);
}
                                   
int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(-1, -1);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Projeto CGra45 grupo 42");

    init();

    manager = new game_manager;

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000 / FPS, timer, 0);

    glutMainLoop();

    delete manager;

    return 0;
}

