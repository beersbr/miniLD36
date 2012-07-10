#ifndef miniLD36_enemy_hpp
#define miniLD36_enemy_hpp

#include "entity.hpp"

class Enemy : public Entity{
public:
    Enemy();
    Enemy(Enemy &);
    int Draw(sf::RenderWindow *rt);
    int Update();
};

#endif
