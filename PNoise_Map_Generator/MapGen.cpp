#define _CRT_SECURE_NO_WARNINGS

#include "MapGen.h"
#include <iostream>

#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

#define __STDC_LIB_EXT1__
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>

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

MapGen::MapGen(int width, int height, float persistance, bool should_display)
	: width(width), height(height), persistance(persistance), should_display(should_display) {
	this->perlin = new Perlin(width, height);

	if (this->should_display) {
		this->display = new Display(width, height);
	}
	else {
		this->display = nullptr;
	}
}

MapGen::~MapGen() {
	delete perlin;
	delete display;
}

void MapGen::start() {
	size_t image_size = (size_t)this->width * (size_t)this->height * RGB_CHANNEL_COUNT;

	unsigned char *image = new unsigned char[image_size];

	if (image == nullptr) {
		std::cout << "Unable to allocate memory for the image" << std::endl;
	}

	combineNoise(image);
	exportImage(image);

	if (this->should_display) {
		this->display->setTexture(image);
		this->display->displayTexture();
	}

	delete[] image;
}

void MapGen::setSeed(int value) {
	this->has_seed = true;
	this->perlin->setSeed(value);
}

void MapGen::setSeaLevel(float value) {
	BiomeManager::setSeaLevel(value);
}

void MapGen::setShouldDisplay(bool value) {
	this->should_display = value;
}

void MapGen::setOctavesNumber(int value) {
	this->octaves = value;
}

void MapGen::exportImage(unsigned char *image) {
	std::time_t t = std::time(0);
	std::tm *now = std::localtime(&t);

	std::stringstream ss;
	ss	<< "maps/" 
		<< now->tm_year + 1900 << "." 
		<< std::setfill('0') << std::setw(2) << now->tm_mon << "." 
		<< now->tm_mday << " " << now->tm_hour << "-" 
		<< std::setfill('0') << std::setw(2) << now->tm_min << "-"
		<< std::setfill('0') << std::setw(2) << now->tm_sec << ".png";

	std::string s = ss.str();

	stbi_write_png(s.c_str(), this->width, this->height, 3, image,
				   3 * this->width);
}
