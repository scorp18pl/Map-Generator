#include "MapGen.h"
#include <iostream>

#define RGB_CHANNEL_COUNT 3

void MapGen::getTerrainColor(float height_v) {
	
}

void MapGen::convertImage(unsigned char *dir, float *src) {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			float r, g, b;
			dir[i * this->width + j] = (uint8_t)(src[i * width + j] * 255.0f);
		}
	}
}

void MapGen::combineNoise(unsigned char *image, int iterations) {
	float *image_f = new float[(size_t)this->width * (size_t)this->height];

	this->perlin->setNoise(image_f, 1);

	for (int i = 0; i < iterations; i++) {
		float pow = powf(2.0f, i);
		this->perlin->addNoise(image_f, 1 / pow, (int)pow);
	}

	//this->perlin->addNoise(image, 0.01f, 4);
	//this->perlin->addNoise(image, 0.001f, 16);
	//this->perlin->addNoise(image, 1.0f, 32);
	convertImage(image, image_f);
}

MapGen::MapGen(int width, int height)
	: width(width), height(height) {
	this->perlin = new Perlin(width, height);
	perlin->setSeed(2137);
	this->display = new Display(width, height);
}

MapGen::~MapGen() {
	delete perlin;
}

void MapGen::start() {
	size_t image_size = (size_t)this->width * (size_t)this->height * RGB_CHANNEL_COUNT;

	unsigned char *image = new unsigned char[image_size];

	if (image == nullptr) {
		std::cout << "Unable to allocate memory for the image" << std::endl;
	}

	combineNoise(image, 8);
	this->display->setTexture(image);
	this->display->displayTexture();

	delete[] image;
}
