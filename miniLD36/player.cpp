#include "player.hpp"

Player::Player() : Entity(){
    this->friction = 0.88;
    this->speed = 0.7f;
}

Player::Player(Player &p) : Entity(p){
    this->friction = 0.88;
    this->speed = 0.7f;
}

int Player::Draw(sf::RenderWindow *rt){
    sf::RectangleShape *s = new sf::RectangleShape();
    s->setFillColor(sf::Color(255, 255, 255));
    s->setPosition(this->x, this->y);
    s->setSize(sf::Vector2<float>(50, 50));
    
    rt->draw(*s);
    
    delete s;
    
    return 0;
}

int Player::Update(Input *i){
    
    if(i->KeyDown(sf::Keyboard::W)){
        this->ay -= this->speed;
    }

    if(i->KeyDown(sf::Keyboard::S)){
        this->ay += this->speed;
    }
    
    if(i->KeyDown(sf::Keyboard::A)){
        this->ax -= this->speed;
    }
    
    if(i->KeyDown(sf::Keyboard::D)){
        this->ax += this->speed;
    }
    
    this->x += this->ax *= this->friction;
    this->y += this->ay *= this->friction;
    
    return 0;
}