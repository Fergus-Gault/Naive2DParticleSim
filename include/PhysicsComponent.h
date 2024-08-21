#pragma once
#include <SFML/Graphics.hpp>
class Particle;
class Window;

class PhysicsComponent {
public:
    void update(Particle& particle, Window& window, sf::Time& deltaTime);

    bool windowCollide(Particle& particle, Window& window);
    const float GRAVITY_CONST{ 1000 };
    float gravity{};
};