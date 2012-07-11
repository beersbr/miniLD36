#ifndef miniLD36_projectile_hpp
#define miniLD36_projectile_hpp

#include "entity.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>

class Projectile : public Entity{
public:
    Projectile();
    Projectile(Projectile&);
    Projectile(float, float, sf::Color c = sf::Color::White);
    Projectile(float, float, float, float, sf::Color c = sf::Color::White);
    
    int Draw(sf::RenderTarget*);
    int Update();
    
private:
    sf::Color color;
};

#endif
