#include "entity.hpp"

Entity::Entity(){
    x = y = z = 0.0f;
    ax = ay = az = 0.0f;
    w = h = 0.0f;
    bx = by = 0.0f;
}

Entity::Entity(Entity &entity){
    x = entity.x;
    y = entity.y;
    z = entity.z;
    
    ax = entity.ax;
    ay = entity.ay;
    az = entity.az;
    
    w = entity.w;
    h = entity.h;
    
    bx = entity.bx;
    by = entity.by;
}

int Entity::Draw(sf::RenderWindow *rt){
    return 1;
}

int Entity::Update(){
    this->bx = this->x - this->w/2;
    this->by = this->y - this->h/2;
    return 0;
}

int Entity::Type(){
    return 0;
}