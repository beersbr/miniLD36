#ifndef miniLD36_entity_h
#define miniLD36_entity_h

#include "input.hpp"
#include <SFML/Graphics.hpp>

enum TYPE{NONE,MONSTER, PLAYER, PROJECTILE};

class Entity{
public:
    Entity();
    Entity(Entity &entity);
    
    virtual int Draw(sf::RenderWindow *);
    virtual int Update();
    
    virtual int Type();
    
protected:
    float x, y, z; // the actual points
    float ax, ay, az; // acceleration
    float w, h; // width and height
    float bx, by; // box x and y, basically top and left.
    TYPE _type;
};

#endif
