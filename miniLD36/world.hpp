#ifndef miniLD36_world_hpp
#define miniLD36_world_hpp

#include <SFML/Graphics.hpp>
#include <iostream>

class World{
public:
    
    static World* Instance();
    
private:
    
    World();
    static World* _instance;
};

#endif
