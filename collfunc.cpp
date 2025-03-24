#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>



struct object {

};

class AABB{

public:

    AABB() {

    }

    bool checkCollision(AABB&);
    void resolveCollision(AABB);
};



bool checkCollision(sf::RectangleShape obj1, sf::RectangleShape obj2 ) {

        if (obj1.getGlobalBounds().intersects(obj2.getGlobalBounds())) {
            // x_pos < x1_pos + width1 && x_pos + width > x1_pos && y_pos < y1_pos + height1 && y_pos + height > y1_pos
            return true;
        }

    return false;
}
void resolveCollision(sf::RectangleShape obj1,  sf::RectangleShape obj2) {
    sf::FloatRect bounds1 = obj1.getGlobalBounds();
    sf::FloatRect bounds2 = obj2.getGlobalBounds();
    sf::Color color;


    float overlapLeft = bounds2.left + bounds2.width - bounds1.left;
    float overlapRight = bounds1.left + bounds1.width - bounds2.left;
    float overlapTop = bounds2.top + bounds2.height - bounds1.top;
    float overlapBottom = bounds1.top + bounds1.height - bounds2.top;

    // Find the smallest overlap and resolve in that direction
    float minOverlap = std::min({overlapLeft, overlapRight, overlapTop, overlapBottom});

    sf::Vector2f currentPos = obj1.getPosition();

    if (minOverlap == overlapLeft) {
        //currentPos.x = bounds2.left + bounds2.width;
        obj1.setFillColor(color.Magenta);
    } else if (minOverlap == overlapRight) {
     //   currentPos.x = bounds2.left - bounds1.width;
        obj1.setFillColor(color.Blue);
    } else if (minOverlap == overlapTop) {
       // currentPos.y = bounds2.top + bounds2.height;
        obj1.setFillColor(color.Red);
    } else if (minOverlap == overlapBottom) {
       // currentPos.y = bounds2.top - bounds1.height;
        obj1.setFillColor(color.Green);
    }

    obj1.setPosition(currentPos);

}






