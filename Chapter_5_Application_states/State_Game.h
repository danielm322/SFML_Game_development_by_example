//
// Created by daniel on 30/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_GAME_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_GAME_H
#include "BaseState.h"
#include "EventManager.h"

class State_Game : public BaseState{
public:
    State_Game(StateManager* l_stateManager);
    ~State_Game();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void MoveSprite(EventDetails* l_details);
    void Draw();

    void MainMenu(EventDetails* l_details);
    void Pause(EventDetails* l_details);
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_increment;
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_GAME_H
