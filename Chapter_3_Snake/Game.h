//
// Created by daniel on 26/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
#include "World.h"
#include "Window.h"
#include "Textbox.h"

class Game {
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
    Window m_window;
    World m_world;
    Snake m_snake;
    Textbox m_textbox;
    sf::Clock m_clock;
    float m_elapsed;
    int m_current_lives;
    int m_current_score;
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_GAME_H
