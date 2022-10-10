#include "gutil.h"
#include "context.h"

#define WIDTH 800
#define HEIGHT 400

int main(int argc, char *argv[]) {
	if (!context_initialize()) {
		return 1;
	}
	Window window = {};
	if (!context_activate_window(&window, WIDTH, HEIGHT, "OpenGL 3D")) {
		return 1;
	}

	printf(
		"\x1b[34mRenderer\x1b[0m: %s\n\x1b[34mOpenGL version\x1b[0m: %s\n\x1b[34mGLSL version\x1b[0m: %s\n",
		glGetString(GL_RENDERER),
		glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION)
	);

	GLfloat triangle_vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 1.0f, 0.0f
	};

	// VAO creation
	unsigned int vao;
	glGenVertexArrays(1, &vao);
	// Bind VAO so VBO gets set inside it
	glBindVertexArray(vao);

	// VBO creation
	unsigned int vbo;
	glGenBuffers(1, &vbo);

	// VBO data setting and vertex attribute setting
	// Bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Set data
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertices), triangle_vertices, GL_STATIC_DRAW);
	// VBO vertex attributes (in variables)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);
	// Unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// Unbind VAO
	glBindVertexArray(0);

	GLuint triangle_program = create_program("dat/shaders/static.vs", "dat/shaders/blue.fs");
	glUseProgram(triangle_program);

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glViewport(0, 0, WIDTH, HEIGHT);
	while (!glfwWindowShouldClose(window.src)) {
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window.src);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glDeleteProgram(triangle_program);

	context_finalize();
	return 0;
}
