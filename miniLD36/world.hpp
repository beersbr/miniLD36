#ifndef miniLD36_world_hpp
#define miniLD36_world_hpp

#include "entity.hpp"
#include "enemy.hpp"
#include "projectile.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>

class World{
public:
    
    static World* Instance();
    std::vector<Entity*> entities;
    
    int Update();
    int Draw(sf::RenderTarget *rt);
    
private:
    
    World();
    static World* _instance;
    std::vector<Entity*>::iterator _entity_it;
    
    sf::Clock clock;
    sf::Time time;
    
    int enemy_count;
};

#endif
