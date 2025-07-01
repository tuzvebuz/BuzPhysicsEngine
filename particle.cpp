//
// Created by esadk on 5/18/2025.
//

#include <iostream>
#include "particle.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <algorithm>

//Particle::Particle(float x, float y, float radius) {

//}
//float calculateMinDistance(std::vector<Particle>& parts) {
    // Need to make a function that gets the closest distance
//}

// std::vector<float> Pos;

// static float const multiplier = std::sqrt(16*16+9*9)/16.0;
bool Particle::checkCollision(std::vector<std::unique_ptr<Particle>>& parts) {
    bool collisionDetected = false;
    for (const auto &other: parts) {
        if (other.get() == this) continue;


 // Bereken de  aanliggende, overstaande zijde in de rechthoekige driehoek tussen deeltjes.
        float a = other->x - x;

        float b = other->y - y;
// Schuine zijde
        float c = sqrt((a*a) + (b*b));
        if (c <= (radius + other->radius)) {
            collisionDetected = true;
            std::cout << "Collision detected";

        }
        // was gonna a draw a line between particles
        sf::VertexArray line(sf::Lines, 2);




    }
    return collisionDetected;




}




