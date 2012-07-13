#include "player.hpp"

Player::Player() : Entity(){
    this->friction = 0.88;
    this->speed = 0.7f;
    this->w = 50;
    this->h = 50;
    this->projectile_color = sf::Color::White;
    this->_type = PLAYER;
}

Player::Player(Player &p) : Entity(p){
    this->friction = 0.88;
    this->speed = 0.7f;
    this->w = 50;
    this->h = 50;
    this->projectile_color = sf::Color::White;
}

int Player::Draw(sf::RenderWindow *rt){
    sf::RectangleShape *s = new sf::RectangleShape();
    s->setFillColor(projectile_color);
    s->setPosition(this->bx, this->by);
    s->setSize(sf::Vector2<float>(this->w, this->h));
    
    rt->draw(*s);
    
    delete s;
    
    return 0;
}

int Player::Update(Input *i, World* w){
    
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
    
    sf::Vector2i *tvec = NULL;
    
    if((tvec = i->Clicked()) != NULL){
        float width = tvec->x - this->x;
        float height = tvec->y - this->y;
        float distance = sqrt(pow(width, 2) + pow(height, 2));
        
        float ax = (width/distance)*8;
        float ay = (height/distance)*8;
        
        ax += this->ax/2;
        ay += this->ay/2;
        
        w->entities.push_back(new Projectile(this->x, this->y, ax, ay));
    }
    
    this->x += this->ax *= this->friction;
    this->y += this->ay *= this->friction;
    
    Entity::Update();
    
    return 0;
}