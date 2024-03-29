#include "projectile.hpp"

Projectile::Projectile() : Entity(){
    this->_type = PROJECTILE;
}

Projectile::Projectile(Projectile &p) : Entity(p){
    this->_type = PROJECTILE;
}

Projectile::Projectile(float x, float y, sf::Color c) : Entity(){
    this->x = x; this->y = y;
    this->w = this->h = 10;
    this->color = c;
    this->_type = PROJECTILE;
    Entity::Update();
}

Projectile::Projectile(float x, float y, float ax, float ay, sf::Color c) : Entity(){
    this->x = x; this->y = y;
    this->w = this->h = 10;
    this->ax = ax; this->ay = ay;
    this->color = c;
    this->_type = PROJECTILE;
    Entity::Update();
}

int Projectile::Draw(sf::RenderTarget* rt){
    sf::RectangleShape *r = new sf::RectangleShape();
    r->setPosition(this->bx, this->by);
//    r->setSize(sf::Vector2<float>(this->w, this->h));
    r->setSize(sf::Vector2<float>(10, 10));
//    r->setFillColor(this->color);
    r->setFillColor(sf::Color(255, 255, 255));
    
    rt->draw(*r);
    
    delete r;
    
    return 0;
}

int Projectile::Update(){
    this->x += this->ax;
    this->y += this->ay;
    
    Entity::Update();
    
    return 0;
}