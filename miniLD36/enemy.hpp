#ifndef miniLD36_enemy_hpp
#define miniLD36_enemy_hpp

#include "entity.hpp"

#include <SFML/Graphics.hpp>

#include <iostream>
#include <assert.h>



class Enemy : public Entity{
public:
    Enemy();
    Enemy(Enemy &);
    int Draw(sf::RenderWindow *rt);
    int Update();
    
private:
    typedef int (Enemy::*enemy_fn)();
    
    bool _moving;
    int _moving_frame_time;
    enemy_fn _movement_fn;
    
    int _pick_function();
    
    int _move_up();
    int _move_left();
    int _move_right();
    int _move_down();
    int _follow();
    int _flee();
    
    static sf::Clock eclock;
};

#endif
