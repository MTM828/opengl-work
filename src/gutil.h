#ifndef GUTIL_H
#define GUTIL_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <GL/glew.h>

#include "util.h"

GLuint make_shader(GLenum type, const char *source, const char *filePath);

GLuint create_shader(GLenum type, const char *filePath);

GLuint make_program(GLuint shader1, GLuint shader2);

GLuint create_program(const char *filePath1, const char *filePath2);

#endif
