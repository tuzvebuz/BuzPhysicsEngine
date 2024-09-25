#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "collfunc.cpp"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600) , "Bouncing Ball");
    window.setFramerateLimit(90);
    sf::RectangleShape rect1(sf::Vector2f(200, 250));
    sf::RectangleShape rect2(sf::Vector2f(100, 150));
    rect2.setPosition(400,200);
    // Main loop
    while (window.isOpen()) {
        // Event handling


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
        // Check for collision
       
        float x_pos = rect1.getPosition().x;
        float y_pos = rect1.getPosition().y;
        float height = rect1.getSize().y;
        float width = rect1.getSize().x;
        float x1_pos = rect2.getPosition().x;
        float y1_pos = rect2.getPosition().y;
        float height1 = rect2.getSize().y;
        float width1 = rect2.getSize().x;
        //float x2_pos = rect2.getPosition().x;
        //float y2_pos = rect2.getPosition().y;

        if (checkCollision(rect1,rect2)) {
            if (x_pos < x1_pos&& y_pos < y1_pos + height1 && y_pos + height > y1_pos) {
                rect1.setPosition(x_pos-1, y_pos);
            }
            if (x_pos > x1_pos&& y_pos < y1_pos + height1 && y_pos + height > y1_pos) {
                rect1.setPosition(x_pos+1, y_pos);
            }
            else if (y_pos < y1_pos && x_pos < x1_pos + width1 && x_pos + width > x1_pos ){
                rect1.setPosition(x_pos,y_pos - 1);

            }
            else if (y_pos > y1_pos && x_pos < x1_pos + width1 && x_pos + width > x1_pos) {
                rect1.setPosition(x_pos, y_pos + 1);

            }
        }
        // Rendering
        window.clear(sf::Color::Black);
        window.draw(rect1);
        window.draw(rect2);
        window.display();
    }


    return 0;
}
