#include "Perlin.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#define __STDC_LIB_EXT1__
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>

#define NUMBER_OF_CHANNELS 1

void Perlin::handleWindowError() {
	if (window == nullptr) {
		std::cout << "An error has occured whilst creating a window." << std::endl;
		glfwTerminate();
		exit(1);
	}
}

void Perlin::initializeGL() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

uint8_t Perlin::getPixelValue(size_t x, size_t y) {
	float x_norm, y_norm;
	x_norm = (float)x / (float)this->width;
	y_norm = (float)y / (float)this->height;
	return (uint8_t)(this->grid->getValue(glm::vec2(x_norm, y_norm)) * 255.0f);
}

Texture *Perlin::generateTexture() {
	int image_size = this->width * this->height * NUMBER_OF_CHANNELS;
	unsigned char *image = (unsigned char *)malloc(image_size);

	if (image == nullptr) {
		std::cout << "Unable to allocate image memory" << std::endl;
		exit(1);
	}

	unsigned char *pixel = image;
	for (size_t x = 0; x < this->width; x++) {
		for (size_t y = 0; y < this->height; y++) {
			pixel += NUMBER_OF_CHANNELS;
			*pixel = getPixelValue(x, y);
		}
	}
	//stbi_write_png("default.png", this->width, this->height,
	//			   NUMBER_OF_CHANNELS, image, this->width * NUMBER_OF_CHANNELS);

	Texture *texture = new Texture(image, this->width, this->height, NUMBER_OF_CHANNELS, 
								   GL_TEXTURE_2D, 0, GL_RED, GL_UNSIGNED_BYTE);


	return texture;
}

void Perlin::displayTexture(Texture *texture) {
	this->shader->activate();
	texture->texUnit(this->shader, "tex0", 0);

	while (!glfwWindowShouldClose(this->window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		this->shader->activate();
		texture->bind();
		this->vao->bind();
		glDrawElements(GL_TRIANGLES, sizeof(this->elements) / sizeof(int), GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(this->window);
		glfwPollEvents();
	}
}

Perlin::Perlin(int window_width, int fside_count) {
	this->width = this->height = window_width;
	
	this->grid = new Grid((size_t)fside_count + 1LU);
	grid->randomize();

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

Perlin::~Perlin() {
	delete this->grid;
	glfwDestroyWindow(this->window);
	delete this->shader;
	delete this->vbo;
	delete this->vao;
	delete this->ebo;
}

void Perlin::start() {
	Texture *texture = generateTexture();

	displayTexture(texture);
}
