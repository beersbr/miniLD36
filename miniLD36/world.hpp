#ifndef miniLD36_world_hpp
#define miniLD36_world_hpp

#include "entity.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

class World{
public:
    
    static World* Instance();
    std::vector<Entity*> entities;
    
private:
    
    World();
    static World* _instance;
};

#endif
