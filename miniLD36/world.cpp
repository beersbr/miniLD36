#include "world.hpp"

World* World::_instance = NULL;

World::World(){
    
}

World* World::Instance(){
    if(!World::_instance) World::_instance = new World();
    return World::_instance;
}