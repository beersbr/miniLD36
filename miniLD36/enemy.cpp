#include "enemy.hpp"

sf::Clock Enemy::eclock;

Enemy::Enemy()  : Entity(){
    this->w = this->h = 30;
    
    this->x = 400; this->y = 300;
    
    this->_type = MONSTER;
    this->_moving = false;
    this->_moving_frame_time = 0;
    
    Entity::Update();
}

Enemy::Enemy(Enemy &e) : Entity(e){
    this->_moving = e._moving;
    this->_moving_frame_time = 0;
    Entity::Update();
}

int Enemy::Draw(sf::RenderWindow *rt){
    
    sf::RectangleShape *s = new sf::RectangleShape();
    s->setFillColor(sf::Color(255, 50, 50));
    s->setPosition(this->bx, this->by);
    s->setSize(sf::Vector2<float>(this->w, this->h));
    
    rt->draw(*s);
    
    delete s;
    
    return 0;
}

int Enemy::Update(){
    
    sf::Time t = Enemy::eclock.getElapsedTime();
    srand(t.asMicroseconds());
    
    if(this->_moving == false){
        this->_pick_function();
        this->_moving_frame_time = (rand()%60+30);
        this->_moving = true;
    }
    
    if(this->x + this->ax > 700){
        this->_movement_fn = &Enemy::_move_left;
        this->_moving_frame_time = 40;
    }
    if(this->x - this->ax < 100){
        this->_movement_fn = &Enemy::_move_right;
        this->_moving_frame_time = 40;
    }
    if(this->y + this->ay > 500){
        this->_movement_fn = &Enemy::_move_up;
        this->_moving_frame_time = 40;
    }
    if(this->y - this->ay < 100){
        this->_movement_fn = &Enemy::_move_down;
        this->_moving_frame_time = 40;
    }
    
    (this->*_movement_fn)();
    
    this->x += this->ax *= 0.88;
    this->y += this->ay *= 0.88;
    
    Entity::Update();
    
    if(this->_moving_frame_time-- == 0){
        this->_moving = false;
    }

    return 0;
}

int Enemy::_pick_function(){

    sf::Time t = Enemy::eclock.getElapsedTime();
    srand(t.asMicroseconds());
    
    int pick = (rand()%4);
    
    switch(pick){
        case 0:
            this->_movement_fn = &Enemy::_move_up;
            break;
        case 1:
            this->_movement_fn = &Enemy::_move_left;
            break;
        case 2:
            this->_movement_fn = &Enemy::_move_down;
            break;
        case 3:
            this->_movement_fn = &Enemy::_move_right;
            break;
    }
    
    return 0;
}

int Enemy::_move_up(){
    this->ay -= 0.3f;
    return 0;
}

int Enemy::_move_left(){
    this->ax -= 0.3f;
    return 0;
}

int Enemy::_move_right(){
    this->ax += 0.3f;
    return 0;
}

int Enemy::_move_down(){
    this->ay += 0.3f;
    return 0;
}

int Enemy::_follow(){
    return 0;
}

int Enemy::_flee(){
    return 0;
}