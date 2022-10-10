#include "gutil.h"

GLuint make_shader(GLenum type, const char *source, const char *file_path) {
	if (source == NULL) {
		printf("\x1b[31mFailed to compile shader, shader is NULL.\x1b[0m\n");
		return 0;
	}
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        GLchar info[length];
        glGetShaderInfoLog(shader, length, NULL, info);
        printf("\x1b[31mFailed to compile shader\x1b[0m: %s\n\x1b[31mError\x1b[0m:\n%s\n", file_path, info);
    }
    return shader;
}

GLuint create_shader(GLenum type, const char *file_path) {
    char *source = read_file(file_path);
    GLuint shader = make_shader(type, source, file_path);
    return shader;
}

GLuint make_program(GLuint shader1, GLuint shader2) {
    GLuint program = glCreateProgram();
    glAttachShader(program, shader1);
    glAttachShader(program, shader2);
    glLinkProgram(program);
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if (status == GL_FALSE) {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        GLchar info[length];
        glGetProgramInfoLog(program, length, NULL, info);
        fprintf(stderr, "glLinkProgram failed: %s\n", info);
    }
    glDetachShader(program, shader1);
    glDetachShader(program, shader2);
    glDeleteShader(shader1);
    glDeleteShader(shader2);
    return program;
}

GLuint create_program(const char *file_path1, const char *file_path2) {
    GLuint shader1 = create_shader(GL_VERTEX_SHADER, (char *) file_path1);
    GLuint shader2 = create_shader(GL_FRAGMENT_SHADER, (char *) file_path2);
    GLuint program = make_program(shader1, shader2);
    return program;
}
