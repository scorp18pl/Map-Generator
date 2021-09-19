#include "MapGen.h"
#include <iostream>

void MapGen::combineNoise(unsigned char *image) {
	this->perlin->addNoise(image, 1.0f, 1);
	this->perlin->addNoise(image, 0.5f, 2);
	//this->perlin->addNoise(image, 0.01f, 4);
	//this->perlin->addNoise(image, 0.001f, 16);
	//this->perlin->addNoise(image, 1.0f, 32);

	for (int i = 0; i < this->width; i++) {
		for (int j = 0; j < this->height; j++) {
			//Intentional overflow
			image[i * width + j] *= 32;
		}
	}
}

MapGen::MapGen(int width, int height)
	: width(width), height(height) {
	this->perlin = new Perlin(width, height);
	this->display = new Display(width, height);
}

MapGen::~MapGen() {
	delete perlin;
}

void MapGen::start() {
	size_t image_size = (size_t)this->width * (size_t)this->height;

	unsigned char *image = new unsigned char[image_size];

	for (size_t i = 0; i < image_size; i++) {
		image[i] = uint8_t(0);
	}

	if (image == nullptr) {
		std::cout << "Unable to allocate memory for the image" << std::endl;
	}

	combineNoise(image);

	this->display->setTexture(image);
	this->display->displayTexture();

	delete[] image;
}
