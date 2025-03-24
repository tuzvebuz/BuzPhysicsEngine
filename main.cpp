#include <math.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "circle.h"





int main() {


    sf::RenderWindow window(sf::VideoMode(800,600), "Circle Collision");

    window.setFramerateLimit(90);
   // circle cirkel1(0, 200, 50.0f, 40.0f, sf::Color::Green);
    // circle cirkel2(200, 50,35.0f,30.0f, sf::Color::Red);

    float moveSpeed = 3.0f;
    sf::Vector2f Velocity(0.0f, 0.0f);

    //cirkel1.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    while (window.isOpen()) {



/*
        // Handle input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            cirkel1.y -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            cirkel1.x -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            cirkel1.y += moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            cirkel1.x += moveSpeed;
        }
        window.draw(triangles);

        // Update circle position
*/

        // Draw everything
        window.clear();
        window.display();
    }
    return 0;
}
