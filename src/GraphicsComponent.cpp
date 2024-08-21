#include "GraphicsComponent.h"
#include "Window.h"
#include "Particle.h"

void GraphicsComponent::update(Particle& particle, Window& window, sf::Time& deltaTime) {
	// Set radius proportional to lifetime and draw
	particle.particle.setRadius(particle.lifetime * particle.radius);
	window.window.draw(particle.particle);
}