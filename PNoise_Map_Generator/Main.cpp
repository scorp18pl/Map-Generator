#include "MapGen.h"

int main() {
	MapGen m(1080, 1080, 0.52f);
	m.setSeed(0);
	m.setSeaLevel(0.52f);
	m.start();
}