#pragma once
#include <SFML/Graphics.hpp>
class Particle;
class Window;

class GraphicsComponent {
public:
	void update(Particle& particle, Window& window, sf::Time& deltaTime);
};