#ifndef miniLD36_player_hpp
#define miniLD36_player_hpp

#include "entity.hpp"
#include <SFML/Graphics.hpp>

class Player : public Entity{
public:
    Player();
    Player(Player &);
    
    int Draw(sf::RenderWindow* rt);
    int Update(Input *i);
    
private:
    float friction;
    float speed;
};

#endif
