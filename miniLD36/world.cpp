#include "world.hpp"

World* World::_instance = NULL;

World::World(){
    this->enemy_count = 1;
}

World* World::Instance(){
    if(!World::_instance) World::_instance = new World();
    return World::_instance;
}

int World::Update(){
    time = clock.getElapsedTime();
    srand(time.asMilliseconds());
    
    if(rand()%1000 < 10){
        if(this->enemy_count < 6){
            this->entities.push_back(new Enemy());
            this->enemy_count += 1;
        }
    }
    
    for(this->_entity_it = this->entities.begin(); this->_entity_it != this->entities.end(); this->_entity_it++){
        
        assert(((*_entity_it)->Type()) != NONE);
        
        switch((*this->_entity_it)->Type()){
            case MONSTER:
                ((Enemy*)(*this->_entity_it))->Update();
                break;
                
            case PROJECTILE:
                ((Projectile*)(*this->_entity_it))->Update();
                break;
        }
    }
    
    return 0;
}

int World::Draw(sf::RenderTarget *rt){
    for(this->_entity_it = this->entities.begin(); this->_entity_it != this->entities.end(); this->_entity_it++){
        
        assert(((*_entity_it)->Type()) != NONE);
        
        switch((*this->_entity_it)->Type()){
            case MONSTER:
                ((Enemy*)(*this->_entity_it))->Draw((sf::RenderWindow*)rt);
                break;
                
            case PROJECTILE:
                ((Projectile*)(*this->_entity_it))->Draw((sf::RenderWindow*)rt);
                break;
        }
    }
    
    return 0;
}