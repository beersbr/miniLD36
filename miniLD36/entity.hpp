#ifndef miniLD36_entity_h
#define miniLD36_entity_h

#include "input.hpp"
#include <SFML/Graphics.hpp>

class Entity{
public:
    Entity();
    Entity(Entity &entity);
    
    virtual int Draw(sf::RenderWindow *);
    virtual int Update();
    
protected:
    float x, y, z; // the actual points
    float ax, ay, az; // acceleration
    float w, h; // width and height
    float bx, by; // box x and y, basically top and left.
};

#endif
