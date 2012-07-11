#ifndef miniLD36_input_hpp
#define miniLD36_input_hpp

#include <iostream>
#include <map>
#include <algorithm>

#include <SFML/Graphics.hpp>

// The input class. This is a singleton class. It handles all the input mouse, keyboard

struct MousePos{
    int x;
    int y;
    int left_click;
    int right_click;
    int middle_click;
};

class Input{
public:
    static Input* Instance();
    int UpdateEvents(sf::Event &e);
    
    int KeyPressed(sf::Keyboard::Key k);
    int KeyDown(sf::Keyboard::Key k);
    
    bool MouseClickedAt(sf::Rect<int>);
    sf::Vector2i* Clicked();
    
private:
    Input();
    static Input *_instance;
    
    std::map<sf::Keyboard::Key, int> keys;
    std::map<sf::Keyboard::Key, int> keysPressed;
    MousePos _mouse_position;
    std::vector<sf::Event> events;
    sf::Vector2i* mouse_click;
};

#endif
