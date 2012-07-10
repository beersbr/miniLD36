#ifndef miniLD36_scene_hpp
#define miniLD36_scene_hpp
#include "input.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Scene{
    Scene();
    Scene(Scene &);
    
    int Draw(sf::RenderTarget *);
    int Update(Input *);
    
//    sf canvas;
};

#endif
