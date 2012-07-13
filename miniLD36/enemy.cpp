#include "enemy.hpp"

Enemy::Enemy()  : Entity(){
    this->_type = MONSTER;
}

Enemy::Enemy(Enemy &e) : Entity(e){
    
}

int Enemy::Draw(sf::RenderWindow *rt){
    
    return 0;
}

int Enemy::Update(){
    
    return 0;
}