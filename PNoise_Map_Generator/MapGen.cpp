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

void MapGen::combineNoise(unsigned char *image) {
	float *image_f = new float[(size_t)this->width * (size_t)this->height];

	this->perlin->setNoise(image_f, 1);

	float weight = this->persistance;
	int pow = 2;
	for (int i = 0; i < this->octaves; i++) {
		this->perlin->addNoise(image_f, weight , pow);
		pow *= 2;
		weight *= this->persistance;
	}

	convertImage(image, image_f);
	delete[] image_f;
}

MapGen::MapGen(int width, int height, float persistance)
	: width(width), height(height), persistance(persistance) {
	this->perlin = new Perlin(width, height);
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

	combineNoise(image);
	this->display->setTexture(image);
	this->display->displayTexture();

	delete[] image;
}

void MapGen::setSeed(int value) {
	this->has_seed = true;
	this->perlin->setSeed(value);
}

void MapGen::setSeaLevel(float value) {
	BiomeManager::setSeaLevel(value);
}

void MapGen::setOctavesNumber(int value) {
	this->octaves = value;
}
