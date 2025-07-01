

#pragma once
#include <vector>
#include <memory>
#include <random>
inline float getRandomFloat1(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist  (min, max);
    return dist(gen);
}



struct Particle {

public:
    float vx,vy;
    float x;
    float y;
    float radius;
    Particle(float x_, float y_, float r_) : x(x_), y(y_), radius(r_) {
        vx = getRandomFloat1(-100.f, 100.f);
        vy = getRandomFloat1(-100.f, 100.f);
    }

    bool checkCollision(std::vector<std::unique_ptr<Particle>>& parts);


};