#version 330 core

in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D tex0;

void main() {
	float r = texture(tex0, texCoord).r;
	float g = texture(tex0, texCoord).g;
	float b = texture(tex0, texCoord).b;
	FragColor = vec4(r, g, b, 1.0f);
}