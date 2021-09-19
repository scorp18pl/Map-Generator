#include "Display.h"
#include <iostream>

#define NUMBER_OF_CHANNELS 1

void Display::handleWindowError() {
	if (window == nullptr) {
		std::cout << "An error has occured whilst creating a window." << std::endl;
		glfwTerminate();
		exit(1);
	}
}

void Display::initializeGL() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Display::setTexture(unsigned char *image) {
	this->texture = new Texture(image, this->width, this->height, NUMBER_OF_CHANNELS,
								   GL_TEXTURE_2D, 0, GL_RED, GL_UNSIGNED_BYTE);
}

Display::Display(int window_width, int window_height) {
	this->width = window_width;
	this->height = window_height;

	initializeGL();

	this->window = glfwCreateWindow((int)window_width, (int)window_width,
									"Map Generator", NULL, NULL);

	handleWindowError();

	glfwMakeContextCurrent(window);
	gladLoadGL();
	glViewport(0, 0, window_width, window_width);

	this->shader = new Shader("perlin.vert", "perlin.frag");

	this->vao = new VAO();
	vao->bind();
	this->vbo = new VertexBuffer(this->vertices, sizeof(this->vertices));
	this->ebo = new ElementBuffer(this->elements, sizeof(this->elements));

	vao->linkAttributes(*this->vbo, 0, 2, GL_FLOAT, 4 * sizeof(float), (void *)0);
	vao->linkAttributes(*this->vbo, 1, 2, GL_FLOAT, 4 * sizeof(float), (void *)(2 * sizeof(float)));

	this->vao->unbind();
	this->vbo->unbind();
	this->ebo->unbind();
}

Display::~Display() {
	glfwDestroyWindow(this->window);
	delete this->shader;
	delete this->vbo;
	delete this->vao;
	delete this->ebo;
}

void Display::displayTexture() {
	this->shader->activate();
	this->texture->texUnit(this->shader, "tex0", 0);

	while (!glfwWindowShouldClose(this->window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		this->shader->activate();
		this->texture->bind();
		this->vao->bind();
		glDrawElements(GL_TRIANGLES, sizeof(this->elements) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}
