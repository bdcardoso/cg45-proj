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

typedef decltype(glutGet(GLUT_ELAPSED_TIME)) glut_time_t;

