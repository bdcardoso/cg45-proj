#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>

void drawSquare() {
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.25, 1.0, 0.25);
    glBegin(GL_POLYGON);
        glVertex3f(0.25, 0.25, 0.0);
        glVertex3f(0.50, 0.25, 0.0);
        glVertex3f(0.50, 0.75, 0.0);
        glVertex3f(0.25, 0.75, 0.0);
    glEnd();
    glColor3f(1.0, 0.25, 0.25);
    glBegin(GL_POLYGON);
        glVertex3f(0.50, 0.25, 0.0);
        glVertex3f(0.75, 0.25, 0.0);
        glVertex3f(0.75, 0.75, 0.0);
        glVertex3f(0.50, 0.75, 0.0);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void init_gl() {
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 1.0, 1.0);
    glOrtho(0.0,  1.0, 0.0,
            1.0, -1.0, 1.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_VIEWPORT);
    glLoadIdentity();

    glScalef(640.f / w, 480.f / h, 1.0);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(320, 240);
    glutInitWindowSize(640, 480);
    glutCreateWindow("CG45 - Lab 1 - Tarefa 3");

    init_gl();

    glutDisplayFunc(drawSquare);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
