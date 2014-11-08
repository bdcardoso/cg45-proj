#include "game_manager.h"
#include "opengl.h"

constexpr int FPS = 60, GAME_WIDTH = 500, GAME_HEIGHT = 400;

void init(void) {
    // glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);

    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHT1);
    glDisable(GL_LIGHT2);
    glDisable(GL_LIGHT3);
    glDisable(GL_LIGHT4);
    glDisable(GL_LIGHT5);
    glDisable(GL_LIGHT6);
    glDisable(GL_LIGHT7);

    game_manager::instance().init(GAME_WIDTH, GAME_HEIGHT);
}

void display() {
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    game_manager::instance().display();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) { game_manager::instance().reshape(w, h); }

void timer(int value) {
    (void)value;

    game_manager::instance().timer();

    glutTimerFunc(1000 / FPS, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    game_manager::instance().keyboard(key, x, y);
}

void keyboardUp(unsigned char key, int x, int y) {
    game_manager::instance().keyboardUp(key, x, y);
}

void special(int key, int x, int y) {
    game_manager::instance().special(key, x, y);
}

void specialUp(int key, int x, int y) {
    game_manager::instance().specialUp(key, x, y);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(-1, -1);
    glutInitWindowSize(GAME_WIDTH, GAME_HEIGHT);
    glutCreateWindow("Projeto CGra45 grupo 42");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    glutSpecialFunc(special);
    glutSpecialUpFunc(specialUp);
    glutReshapeFunc(reshape);

    glutTimerFunc(1000 / FPS, timer, 0);

    glutMainLoop();

    return 0;
}
