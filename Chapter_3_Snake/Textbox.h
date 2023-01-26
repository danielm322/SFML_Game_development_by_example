//
// Created by daniel on 26/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTBOX_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

using MessageContainer = std::vector<std::string>;
class Textbox{
public:
    Textbox();
    Textbox(int l_visible, int l_charSize,
            int l_width, sf::Vector2f l_screenPos);
    ~Textbox();
    void Setup(int l_visible, int l_charSize,
               int l_width, sf::Vector2f l_screenPos);
    void Add(std::string l_message);
    void Clear();
    void Render(sf::RenderWindow& l_wind);
private:
    MessageContainer m_messages;
    int m_numVisible;
    sf::RectangleShape m_backdrop;
    sf::Font m_font;
    sf::Text m_content;
};

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTBOX_H
