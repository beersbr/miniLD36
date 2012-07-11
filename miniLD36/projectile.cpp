#include "projectile.hpp"

Projectile::Projectile() : Entity(){
    
}

Projectile::Projectile(Projectile &p) : Entity(p){
    
}

Projectile::Projectile(float x, float y, sf::Color c) : Entity(){
    this->x = x; this->y = y;
    this->color = c;
}

Projectile::Projectile(float x, float y, float ax, float ay, sf::Color c = sf::Color::White) : Entity(){
    this->x = x; this->y = y;
    this->ax = ax; this->ay = ay;
    this->color = c;
}

int Projectile::Draw(sf::RenderTarget* rt){
    sf::RectangleShape *r = new sf::RectangleShape();
    r->setPosition(this->bx, this->by);
    r->setSize(sf::Vector2<float>(this->w, this->h));
    r->setFillColor(this->color);
    
    rt->draw(*r);
    
    delete r;
    
    return 0;
}

int Projectile::Update(){
    this->x += this->ax;
    this->y += this->ay;
    return 0;
}