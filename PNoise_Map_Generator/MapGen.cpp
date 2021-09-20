#include "MapGen.h"
#include <iostream>

#define RGB_CHANNEL_COUNT 3

void MapGen::convertImage(unsigned char *dir, float *src) {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++) {
			RGB color = BiomeManager::getColor(1.0f - src[i * width + j]);
			unsigned char *pixel;
			pixel = dir + ((size_t)i * (size_t)this->width + (size_t)j) * RGB_CHANNEL_COUNT;
			*(pixel) = color.r;
			*(pixel + 1) = color.g;
			*(pixel + 2) = color.b;
		}
	}
}

void MapGen::combineNoise(unsigned char *image, int iterations) {
	float *image_f = new float[(size_t)this->width * (size_t)this->height];

	this->perlin->setNoise(image_f, 1);

	for (int i = 0; i < iterations; i++) {
		float pow = powf(2.0f, i + 1);
		this->perlin->addNoise(image_f, 1.0f / pow , (int)pow);
	}

	convertImage(image, image_f);
}

MapGen::MapGen(int width, int height)
	: width(width), height(height) {
	this->perlin = new Perlin(width, height);
	//perlin->setSeed(2137);
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
