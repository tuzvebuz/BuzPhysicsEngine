#include <cmath>
#include <iostream>
#include "collfunc.cpp"
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600) , "Bounding box collision");
    window.setFramerateLimit(90);
    sf::RectangleShape rect1(sf::Vector2f(200, 250));
    sf::RectangleShape rect2(sf::Vector2f(100, 150));
    rect2.setPosition(400,200);
    // Main loop
    sf::Event event;

    sf::Color color;
    while (window.isOpen()) {
        // Event handling
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Movement for rect 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            rect1.setPosition(rect1.getPosition().x, rect1.getPosition().y - 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            rect1.setPosition(rect1.getPosition().x - 3, rect1.getPosition().y);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            rect1.setPosition(rect1.getPosition().x, rect1.getPosition().y + 3);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            rect1.setPosition(rect1.getPosition().x + 3, rect1.getPosition().y);
        }
        sf::FloatRect bounds1 = rect1.getGlobalBounds();
        sf::FloatRect bounds2 = rect2.getGlobalBounds();

        if (checkCollision(rect1,rect2)) {

            sf::Color color;
            resolveCollision(rect1,rect2);
        }
        // Rendering
        window.clear(sf::Color::Black);
        window.draw(rect1);
        window.draw(rect2);
        window.display();
    }


    return 0;
}