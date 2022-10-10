#include "context.h"

void glfw_error_callback(int error, const char *description) {
	fprintf(stderr, "GLFW error (from callback): %s\n", description);
}

bool context_initialize() {
	if (!glfwInit()) {
		return false;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	// I mean, MacOS isn't supported yet, but I'm leaving this here for when it is.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	glfwSetErrorCallback(glfw_error_callback);
	return true;
}

void context_finalize(void) {
	glfwTerminate();
}

bool context_activate_window(Window *window, int w, int h, const char *title) {
	window->src = glfwCreateWindow(w, h, title, NULL, NULL);
	if (window->src) {
		// Context creation succeeded
		glfwMakeContextCurrent(window->src);
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK) {
			return false;
		}
		return true;
	} else {
		// Context creation failed
		return false;
	}
}
