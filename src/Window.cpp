#include "Window.h"
#include "PhysicsComponent.h"
#include "GraphicsComponent.h"
#include "ParticleManager.h"

// Create a new window with a particle manager
Window::Window(ParticleManager* particleManager) 
	: window(sf::VideoMode(800, 600), "Particle Sim")
	, particleManager_(particleManager)
{}

void Window::processEvents() {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0.f, 0.f, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
			window.setView(sf::View(visibleArea));
		}
		// Create particles while LMB is pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			mousePos = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
			particleManager_->createParticle(mousePos);
		}
	}
}

void Window::update(sf::Time deltaTime) {
	window.clear();
	
	// Update all particles
	particleManager_->update(*this, deltaTime);

	window.display();
}

void Window::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		processEvents();
		update(clock.restart());
	}
}

