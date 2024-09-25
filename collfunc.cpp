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

    float getPosition();
};



bool checkCollision(sf::RectangleShape obj1, sf::RectangleShape obj2 ) {

        // Check for collision
        float x_pos = obj1.getPosition().x;
        float y_pos = obj1.getPosition().y;
        float height = obj1.getSize().y;
        float width = obj1.getSize().x;
        float x1_pos = obj2.getPosition().x;
        float y1_pos = obj2.getPosition().y;
        float height1 = obj2.getSize().y;
        float width1 = obj2.getSize().x;
        std::cout << "hoi" << std::endl;
        if (x_pos < x1_pos + width1 && x_pos + width > x1_pos && y_pos < y1_pos + height1 && y_pos + height > y1_pos) {
            return true;
        }



    return false;
}
float handleCollision() {






    return 0;
}



