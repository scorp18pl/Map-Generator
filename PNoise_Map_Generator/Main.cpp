#include "MapGen.h"

#include <iostream>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	size_t map_count;
	std::cout << "Insert map count" << std::endl;
	std::cin >> map_count;

	for (int i = 0; i < map_count; i++) {
		MapGen m(1080, 1080, 0.6f, true);
		//m.setSeed(4);
		m.setSeaLevel(0.52f);
		m.start();
	}

	system("pause");
}