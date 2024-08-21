#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class ParticleManager;

class Window {
public:
	Window(ParticleManager* particleManager);

	~Window() = default;
	sf::RenderWindow window;

	void processEvents();
	void update(sf::Time deltaTime);

	void run();

	sf::Vector2f dimensions() { return static_cast<sf::Vector2f>(window.getSize()); }


	sf::Vector2f mousePos{};
private:
	ParticleManager* particleManager_;
};