#version 330 core
layout (location = 0) in vec3 point_pos;

void main() {
	gl_Position = vec4(point_pos.x, point_pos.y, point_pos.z, 1.0f);
}
