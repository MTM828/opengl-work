#ifndef GLUTIL_H
#define GLUTIL_H

#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "util.h"

GLuint make_buffer(GLfloat *data);

void del_buffer(GLuint buffer);

unsigned int gen_vbo(float *vertices, int vertex_size);

unsigned int gen_vao();

GLuint make_shader(GLenum type, const char *source, const char *filePath);

GLuint create_shader(GLenum type, const char *filePath);

GLuint make_program(GLuint shader1, GLuint shader2);

GLuint create_program(const char *filePath1, const char *filePath2);

#endif
