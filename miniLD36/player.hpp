#ifndef miniLD36_player_hpp
#define miniLD36_player_hpp

#include "entity.hpp"
#include "world.hpp"
#include "projectile.hpp"
#include <SFML/Graphics.hpp>

extern std::vector<Entity*> Entities;

class Player : public Entity{
public:
    Player();
    Player(Player &);
    
    int Draw(sf::RenderWindow* rt);
    int Update(Input *i, World* w);
    
    sf::Color GetColor();
    
private:
    float friction;
    float speed;
    
    sf::Color projectile_color;
};

#endif
