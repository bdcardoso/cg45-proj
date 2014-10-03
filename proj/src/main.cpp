#include "game_manager.h"
#include "opengl.h"

game_manager *manager = nullptr;
constexpr int FPS = 60;

void init(void) {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    GLfloat global_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat shininess[] = { 1.0 };
    GLfloat light_pos[]  = { 0.0, 25.0, 0.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

}

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
    glutCreateWindow("Projeto CGra45 grupo 42");

    glEnable(GL_DEPTH_TEST);

    init();

    manager = new game_manager;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000 / FPS, timer, 0);

    glutMainLoop();

    delete manager;

    return 0;
}

