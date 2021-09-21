#include "MapGen.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	for (int i = 0; i < 3; i++) {
		MapGen m(1080, 1080, 0.6f, false);
		//m.setSeed(4);
		m.setSeaLevel(0.52f);
		m.start();
	}

	system("pause");
}