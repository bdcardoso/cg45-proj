#pragma once
#ifdef _WIN32
// TODO
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

typedef GLdouble glut_time_t;

void gluxSlicedCube(int sx, int sy, int sz);
