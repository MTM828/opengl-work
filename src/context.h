#ifndef CONTEXT_H
#define CONTEXT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct Window {
	GLFWwindow *src;
} Window;

bool context_initialize();

void context_finalize();

bool context_activate_window(Window *window, int w, int h, const char *title);

#endif
