#include <SFML/Graphics.hpp>
#include "particle.h"




void makeParticle() {
  Particle p;
  p.size = // Random shit
           //
}


int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(200,200), "Hello From SFML");
    Particle particle;

    sf::Clock clock;
    particle.size = 5.f;
    particle.x = 0;
    particle.y = 0;
    particle.velocity = 10.f;
    
    std::vector<Particle> particles;
    
    sf::CircleShape shape(particle.size);
    shape.setPosition(particle.x, particle.y);
    shape.setFillColor(sf::Color::White);
    
    int amountParticles = 0;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              amountParticles += 1;

              makeParticle();
            }
            
        }
        window.clear();
        window.draw(shape);
        window.display();
        
    }

    return 0;
}
