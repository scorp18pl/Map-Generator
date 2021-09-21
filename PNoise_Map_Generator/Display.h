#ifndef DISPLAY_CLASS_H
#define DISPLAY_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "VAO.h"
#include "ElementBuffer.h"
#include "Shader.h"
#include "Texture.h"


class Display {
private:
	int width, height;

	GLfloat vertices[4 * (2 + 2)] = {
		//Vertex Coordinates	//Texture Coordinates
		-1.0f,  1.0f,			0.0f, 1.0f,
		 1.0f,  1.0f,			1.0f, 1.0f,
		 1.0f, -1.0f,			1.0f, 0.0f,
		-1.0f, -1.0f,			0.0f, 0.0f
	};

	GLuint elements[6] = {
		0, 1, 3,
		1, 2, 3
	};

	Texture *texture = nullptr;
	GLFWwindow *window;
	Shader *shader;

	VertexBuffer *vbo;
	VAO *vao;
	ElementBuffer *ebo;

	void handleWindowError();
	void initializeGL();
public:
	Display(int window_width, int window_height);
	~Display();

	void setTexture(unsigned char *image);
	void displayTexture();
};

#endif

