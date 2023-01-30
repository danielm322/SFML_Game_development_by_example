//
// Created by daniel on 30/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_INTRO_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_INTRO_H
#include "BaseState.h"
#include "EventManager.h"

class State_Intro : public BaseState{
public:
    State_Intro(StateManager* l_stateManager);
    ~State_Intro();

    void OnCreate();
    void OnDestroy();

    void Activate();
    void Deactivate();

    void Update(const sf::Time& l_time);
    void Draw();

    void Continue(EventDetails* l_details);
private:
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Font m_font;
    sf::Text m_text;

    float m_timePassed;
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_STATE_INTRO_H
