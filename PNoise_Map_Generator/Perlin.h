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
	unsigned int width, height;
	Grid grid;

	GLFWwindow *window;
	VertexBuffer vbo;
	VAO vao;
	ElementBuffer ebo;
	Shader shader;
public:
	Perlin();
};

#endif