#version core 330

layout (location = 0) in vec2 in_pos;
layout (location = 1) in vec2 in_tex_coord;

out vec2 tex_coord;

void main() {
	gl_Position = vec3(in_pos.x, in_pos.y, 0.0f);

	tex_coord = in_tex_coord;
}