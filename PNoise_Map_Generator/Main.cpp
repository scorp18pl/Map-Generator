#include "MapGen.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	for (;;) {
		MapGen m(1080, 1080, 0.6f, true);
		//m.setSeed(4);
		m.setSeaLevel(0.52f);
		m.start();
	}

	system("pause");
}