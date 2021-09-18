#version 330 core

in vec2 tex_coord;

out vec4 FragColor;

uniform sampler2D tex0;

void main() {
	FragColor = texture(tex0, tex_coord);
}