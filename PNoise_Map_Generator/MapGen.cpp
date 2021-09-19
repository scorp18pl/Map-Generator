#include "MapGen.h"
#include <iostream>

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

	if (image == nullptr) {
		std::cout << "Unable to allocate memory for the image" << std::endl;
	}

	this->perlin->getNoise(image, 1);
	this->display->setTexture(image);
	this->display->displayTexture();

	delete[] image;
}
