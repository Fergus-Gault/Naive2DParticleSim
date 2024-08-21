#include "PhysicsComponent.h"
#include "Particle.h"

void PhysicsComponent::update(Particle& particle, Window& window, sf::Time& deltaTime) {
	// Decrease lifetime
	particle.lifetime -= deltaTime.asSeconds();

	// If particles collides with window, set its y position to the window size
	if (windowCollide(particle, window)) {
		particle.particle.setPosition(sf::Vector2f(particle.particle.getPosition().x, window.dimensions().y - particle.particle.getRadius()));
		particle.velocity.y = 0;
		gravity = 0;
	}
	else { // Renable gravity if no longer touching window
		gravity = GRAVITY_CONST;
		particle.velocity.y += gravity * deltaTime.asSeconds();
		particle.particle.move(sf::Vector2f(0.f, particle.velocity.y * deltaTime.asSeconds()));
	}
}

// Return true if colliding with window
bool PhysicsComponent::windowCollide(Particle& particle, Window& window) {
	return particle.particle.getPosition().y + particle.particle.getRadius() >= window.dimensions().y;
}

