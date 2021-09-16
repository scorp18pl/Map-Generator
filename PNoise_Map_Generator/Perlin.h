#ifndef PERLIN_CLASS_H
#define PERLIN_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Grid.h"
#include "VertexBuffer.h"
#include "VAO.h"
#include "ElementBuffer.h"
#include "Shader.h"

class Perlin {
private:
	int width, height;
	Grid *grid;

	GLfloat vertices[8] = {
		-1.0f,  1.0f,
		 1.0f,  1.0f,
		 1.0f, -1.0f,
		-1.0f, -1.0f
	};

	GLuint elements[6] = {
		0, 1, 3,
		1, 2, 3
	};

	GLFWwindow *window;
	Shader *shader;

	VertexBuffer *vbo;
	VAO *vao;
	ElementBuffer *ebo;

	void handleWindowError();
	void initializeGL();

	uint8_t getPixelValue(size_t x, size_t y);

	void generateImage();
	void displayImage();
public:
	Perlin(int window_width, int fside_count);
	~Perlin();
	
	void start();
};

#endif