#include "Game.hpp"
#include "Input.hpp"
#include "Player.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "ResourcePath.hpp"

#include <iostream>
#include <cstdlib>

// drop color towers and shoot enemies through the color towers. the color should be the opposite to that of the enemy. IE (255, 255, 255) is opposite of (0, 0, 0) && (255, 0, 255) is opposite of (0, 255, 0)

// color is constantly changing

int main (int argc, const char * argv[])
{
    sf::RenderWindow window(sf::VideoMode(Game::Width, Game::Height), "Color");
    window.setFramerateLimit(Game::Framerate);
    window.setVerticalSyncEnabled(true);
    
    sf::Event event;
    Input* input = Input::Instance();

    World* world = World::Instance();
    
    world->entities.push_back(new Enemy());
    
    Player* p = new Player();

    while(Game::IsPlaying){
        input->ResetEvents();
        while(window.pollEvent(event)){
            input->UpdateEvents(event);
        }
        
        if(input->KeyDown(sf::Keyboard::Escape)){
            window.close();
            Game::IsPlaying = false;
        }

        p->Update(input, world);
        world->Update();
        
        window.clear();
        world->Draw(&window);
        p->Draw(&window);
        window.display();
    }

	return EXIT_SUCCESS;
}
