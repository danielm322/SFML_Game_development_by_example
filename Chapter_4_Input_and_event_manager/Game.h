//
// Created by daniel on 25/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
#include "Window.h"

class Game{
public:
    Game();
    ~Game();

//    void HandleInput();
    void Update();
    void Render();
    void MoveSprite(EventDetails* l_details);

    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();
private:
    void MoveMushroom();

    Window m_window;
    sf::Clock m_clock;
//    sf::Time m_elapsed;

    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
//    sf::Vector2i m_increment;
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
