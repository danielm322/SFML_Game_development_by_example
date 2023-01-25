//
// Created by daniel on 25/01/23.
//

#pragma once
#include "Window.h"

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H

class Game{
public:
    Game();
    ~Game();

    void HandleInput();
    void Update();
    void Render();

    Window* GetWindow();

    sf::Time GetElapsed();
    void RestartClock();
private:
    void MoveMushroom();

    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;

    sf::Texture m_mushroomTexture;
    sf::Sprite m_mushroom;
    sf::Vector2i m_increment;
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
