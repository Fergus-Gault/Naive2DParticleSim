#include "window.h"
#include "ParticleManager.h"

int main() {
	Window window(new ParticleManager);
	window.run();

	return EXIT_SUCCESS;
}