#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Bouncing Ball");
    window.setFramerateLimit(60);

    // Ball settings
    sf::RectangleShape rectangle(sf::Vector2f(200.f, 100.f));
    sf::CircleShape ball(20.0f);
    ball.setFillColor(sf::Color::Red);

    ball.setOrigin(ball.getRadius(), ball.getRadius());
    float groundLevel = window.getSize().y - ball.getRadius();
    ball.setPosition(window.getSize().x / 2, 40);  // Start at ground level
    rectangle.setPosition(window.getSize().x / 2,400);
    // Physics settings
    float gravity = 9.8f;  // Acceleration due to gravity (m/s^2)
    float speed = 0.0f;  // Current speed of the ball (m/s)
    float coefficientOfRestitution = 0.8f;  // Coefficient of restitution
    float deltaTime = 0.016f;  // 60 fps

    // Ball state
    bool isFalling = true;

    // Main loop
    while (window.isOpen()) {
        // Event handling


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
            ball.setPosition(window.getSize().x / 2, 100);
        }
        if (ball.getPosition().y >= rectangle.getPosition().y && ball.getPosition().x == rectangle.getPosition().x) {
            if (ball.getPosition().y - ball.getRadius() >= rectangle.getPosition().y) {
                ball.setPosition(ball.getPosition().x, rectangle.getPosition().y);  // Reset position to ground level
                speed = -speed * coefficientOfRestitution;  // Reverse speed and apply restitution
                if (std::abs(speed) < 1.0f) {  // Stop bouncing if the speed is too low
                    isFalling = false;
                }
            }
            ball.setPosition(ball.getPosition().x, rectangle.getPosition().y);
            speed = -speed * coefficientOfRestitution;
            if (std::abs(speed) < 1.0f) {
                isFalling = false;
            }
        }

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        // Physics update
        if (isFalling) {
            // Apply gravity to the ball
            speed += gravity * deltaTime;
            ball.move(0, speed);



            if (ball.getPosition().y >= groundLevel) {
                ball.setPosition(ball.getPosition().x, groundLevel);
                speed = -speed * coefficientOfRestitution;
                if (std::abs(speed) < 1.0f) {
                    isFalling = false;
                }
            }
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                isFalling = true;
                speed = -std::sqrt(2 * gravity * 100);
            }
        }

        // Rendering
        window.clear(sf::Color::Black);
        window.draw(ball);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
