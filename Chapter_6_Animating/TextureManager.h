//
// Created by daniel on 31/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTUREMANAGER_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTUREMANAGER_H
#include "ResourceManager.h"
#include <SFML/Graphics/Texture.hpp>

class TextureManager:
        public ResourceManager<TextureManager, sf::Texture>
{
public:
    TextureManager(): ResourceManager("Resources/textures.cfg"){}
    sf::Texture* Load(const std::string& l_path){
        sf::Texture* texture = new sf::Texture();
        if(!texture->loadFromFile(
                Utils::GetWorkingDirectory() + l_path))
        {
            delete texture;
            texture = nullptr;
            std::cerr << "! Failed to load texture: "
                      << l_path << std::endl;
        }
        return texture;
    }
};

#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_TEXTUREMANAGER_H
