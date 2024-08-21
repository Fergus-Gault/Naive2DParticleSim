#pragma once

#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "Window.h"
#include <SFML/Graphics.hpp>


class Particle {
public:

	sf::Vector2f velocity{};
	sf::CircleShape particle;
	float radius{ 7.f };
	float lifetime{2.f};

	Particle(PhysicsComponent* physics,
		GraphicsComponent* graphics,
		sf::Vector2f position)
		: physics_(physics),
		graphics_(graphics)
	{
		particle.setRadius(radius);
		particle.setOrigin(radius, radius); // Set origin to center of circle
		particle.setPosition(position);
		particle.setFillColor(sf::Color(rand() % 255+1, rand() % 255+1, rand() % 255+1));
	}

	void update(Window& window, sf::Time& deltaTime) {
		physics_->update(*this, window, deltaTime);
		graphics_->update(*this, window, deltaTime);
	}


private:
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};