#include "ParticleManager.h"
#include "Window.h"
#include <math.h>

void ParticleManager::createParticle(sf::Vector2f& position) {
	particles.push_back(new Particle(new PhysicsComponent(), new GraphicsComponent(), position));
}

void ParticleManager::update(Window& window, sf::Time deltaTime){
    // For each particle, iterate over every other particle
	for (auto& particle : particles) {
		for (auto& other : particles) {
			if (particle != other) {
				if (particleCollide(*particle, *other)) {
					handleCollision(*particle, *other); // If they collide then handle
				}
			}
		}
		particle->update(window, deltaTime);
		if (particle->lifetime < 0) { // Delete pointer to particle if it is dead
			delete particle;
		}
	}

    // Remove dead particles from vector
	particles.erase(std::remove_if(particles.begin(), particles.end(),
		[](Particle* p) {return p->lifetime < 0; }), particles.end());

}

bool ParticleManager::particleCollide(Particle& particle, Particle& other) {
    // Calculate differences in positions
	float xDiff = std::abs(particle.particle.getPosition().x - other.particle.getPosition().x);
	float yDiff = std::abs(particle.particle.getPosition().y - other.particle.getPosition().y);

    // Calculate distance between particles
    float distanceBetween = std::sqrt(xDiff * xDiff + yDiff * yDiff);

    // Calculate sum of rad
	float sumOfRad = particle.particle.getRadius() + other.particle.getRadius();

    // Return true if particles collide
	return sumOfRad >= distanceBetween;
}

void ParticleManager::handleCollision(Particle& particle, Particle& other) {
    // Calculate the difference in positions
    float xDiff = other.particle.getPosition().x - particle.particle.getPosition().x;
    float yDiff = other.particle.getPosition().y - particle.particle.getPosition().y;

    // Calculate the distance between the centers of the particles
    float distanceBetween = std::sqrt(xDiff * xDiff + yDiff * yDiff);

    // Check for the division by zero case
    if (distanceBetween == 0) {
        // Handle the special case where the particles are exactly overlapping
        xDiff = 1.0f; // Default direction (arbitrary)
        yDiff = 0.0f; // Default direction (arbitrary)
        distanceBetween = 1.0f; // Prevent division by zero
    }

    // Calculate the sum of the radii
    float sumOfRad = particle.particle.getRadius() + other.particle.getRadius();

    // Calculate the overlap distance
    float overlap = sumOfRad - distanceBetween;

    // Normalize the vector between the centers
    float normalX = xDiff / distanceBetween;
    float normalY = yDiff / distanceBetween;

    // Move the particles apart by half the overlap distance each
    particle.particle.move(-normalX * (overlap / 2), -normalY * (overlap / 2));
    other.particle.move(normalX * (overlap / 2), normalY * (overlap / 2));
}
