#pragma once
class Map {
private:
	int width, height, seed;
	float *data;

public:
	Map(int width, int height, int seed);
	~Map();

	float *getData();
	void setData(float *data);
};

