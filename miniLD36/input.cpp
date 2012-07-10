#include "input.hpp"

Input::Input(){
    
}

Input* Input::_instance = NULL;

Input* Input::instance(){
    if(!Input::_instance) Input::_instance = new Input();
    return Input::_instance;
}

int Input::UpdateEvents(sf::Event &e){
    switch(e.type){
        case sf::Event::KeyPressed:
            this->keys[e.key.code] = 1;
            break;
            
        case sf::Event::KeyReleased:
            this->keys[e.key.code] = 0;
            break;
            
        case sf::Event::MouseButtonPressed:
//            std::cout << "Mouse button pressed: " << e.mouseButton.x << ", " << e.mouseButton.y << std::endl;
//            std::cout << "Mouse button: " << e.mouseButton.button << std::endl;
            break;
            
        case sf::Event::MouseButtonReleased:
            break;
            
        case sf::Event::MouseMoved:
            this->_mouse_position.x = e.mouseMove.x;
            this->_mouse_position.y = e.mouseMove.y;
//            std::cout << "Mouse pos at: " << this->_mouse_position.x << ", " << this->_mouse_position.x << std::endl;
            break;
    }

    return 0;
}

int Input::KeyDown(sf::Keyboard::Key k){
    if(this->keys[k] != 0) return true;
    return false;
}

bool Input::MouseClickedAt(sf::Rect<int> r){
    if(r.contains(this->mouse_click)) return true;
    return false;
}