#include "game_manager.h"
#include "opengl.h"

game_manager *manager = nullptr;
constexpr int FPS = 60, GAME_WIDTH = 500, GAME_HEIGHT = 400;

void init(void) { glEnable(GL_DEPTH_TEST); }

void display() {
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    manager->display();
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) { manager->reshape(w, h); }

void timer(int value) {
    (void)value;

    manager->timer();

    glutTimerFunc(1000 / FPS, timer, 0);
}

void keyboard(unsigned char key, int x, int y) { manager->keyboard(key, x, y); }

void keyboardUp(unsigned char key, int x, int y) {
    manager->keyboardUp(key, x, y);
}

void special(int key, int x, int y) { manager->special(key, x, y); }

void specialUp(int key, int x, int y) { manager->specialUp(key, x, y); }

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(-1, -1);
    glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);
    glutCreateWindow("Projeto CGra45 grupo 42");

    init();

    manager = new game_manager(GAME_WIDTH, GAME_HEIGHT);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000 / FPS, timer, 0);

    glutMainLoop();

    delete manager;

    return 0;
}
