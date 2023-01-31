//
// Created by daniel on 31/01/23.
//

#ifndef SFML_GAME_DEVELOPMENT_BY_EXAMPLE_ANIM_DIRECTIONAL_H
#define SFML_GAME_DEVELOPMENT_BY_EXAMPLE_ANIM_DIRECTIONAL_H

#include "Anim_Base.h"
#include "Directions.h"

class Anim_Directional : public Anim_Base{
protected:
    void FrameStep();
    void CropSprite();
    void ReadIn(std::stringstream& l_stream);
};


#endif //SFML_GAME_DEVELOPMENT_BY_EXAMPLE_ANIM_DIRECTIONAL_H
