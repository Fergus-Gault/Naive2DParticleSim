#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <Particle.h>

class Window;

class ParticleManager {
public:
	void update(Window& window, sf::Time deltaTime);
	std::vector<Particle*> particles;
	void createParticle(sf::Vector2f& mousePos);
	bool particleCollide(Particle& particle, Particle& other);
	void handleCollision(Particle& particle, Particle& other);
};
