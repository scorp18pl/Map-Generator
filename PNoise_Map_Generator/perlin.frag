#version 330 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D tex0;

void main() {
	float p = texture(tex0, texCoord).r;
	FragColor = vec4(p, p, p, 1.0f);
}