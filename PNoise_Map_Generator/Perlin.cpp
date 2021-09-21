#include "Perlin.h"

#define NUMBER_OF_ITERATIONS 1

float Perlin::getPixelValue(int x, int y) {
	float x_norm, y_norm;
	x_norm = (float)x / (float)this->width;
	y_norm = (float)y / (float)this->height;
	return this->grid->getValue(glm::vec2(x_norm, y_norm));
}

Perlin::Perlin(int window_width, int window_height) {
	this->width = window_width;
	this->height = window_height;

	this->grid = new Grid(2, 2);
}

Perlin::~Perlin() {
	delete this->grid;
}

void Perlin::setSeed(int seed) {
	this->grid->setSeed(seed);
}

void Perlin::addNoise(float *image, float weight, int num_fields_x, int num_fields_y) {
	assert(weight >= 0.0f && weight <= 1.0f);
	this->grid->resize(num_fields_x + 1, num_fields_y + 1);

	for (int x = 0; x < this->width; x++) {
		for (int y = 0; y < this->height; y++) {
			image[x * height + y] += weight * getPixelValue(x, y);
			image[x * height + y] /= weight + 1.0f;
		}
	}
}

void Perlin::addNoise(float *image, float weight, int num_fields) {
	addNoise(image, weight, num_fields, num_fields);
}

void Perlin::setNoise(float *image, int num_fields_x, int num_fields_y) {
	this->grid->resize(num_fields_x + 1, num_fields_y + 1);

	for (int x = 0; x < this->width; x++) {
		for (int y = 0; y < this->height; y++) {
			image[x * height + y] = getPixelValue(x, y);
		}
	}
}

void Perlin::setNoise(float *image, int num_fields) {
	setNoise(image, num_fields, num_fields);
}
