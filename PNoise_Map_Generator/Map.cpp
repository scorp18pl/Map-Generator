#include "Map.h"

Map::Map(int width, int height, int seed) 
	:width(width), height(height), seed(seed) {
	this->data = nullptr;
}

Map::~Map() {
	delete this->data;
}

float *Map::getData() {
	return this->data;
}

void Map::setData(float *data) {
	this->data = data;
}
