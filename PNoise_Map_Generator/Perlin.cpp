#include "Perlin.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#define __STDC_LIB_EXT1__
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>
#include <iostream>

#define NUMBER_OF_ITERATIONS 1

uint8_t Perlin::getPixelValue(int x, int y) {
	float x_norm, y_norm;
	x_norm = (float)x / (float)this->width;
	y_norm = (float)y / (float)this->height;
	return (uint8_t)(this->grid->getValue(glm::vec2(x_norm, y_norm)) * 255.0f);
}

Perlin::Perlin(int window_width, int window_height) {
	this->width = window_width;
	this->height = window_height;

	this->grid = new Grid(2, 2);
}

Perlin::~Perlin() {
	delete this->grid;
}

void Perlin::addNoise(unsigned char *image, float weight, int num_fields_x, int num_fields_y) {
	assert(weight >= 0.0f && weight <= 1.0f);
	this->grid->resize(num_fields_x + 1, num_fields_y + 1);

	for (int x = 0; x < this->width; x++) {
		for (int y = 0; y < this->height; y++) {
			image[x * height + y] = (uint8_t)((float)image[x * height + y] * (1.0f - weight));
			image[x * height + y] += (uint8_t)(weight * (float)getPixelValue(x, y));
		}
	}
}

void Perlin::addNoise(unsigned char *image, float weight, int num_fields) {
	addNoise(image, weight, num_fields, num_fields);
}
