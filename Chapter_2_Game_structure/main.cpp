//
// Created by daniel on 25/01/23.
//

#include "Game.h"
int main(int argc, char* argv[]){
// Program entry point.
    Game game; // Creating our game object.
    while(!game.GetWindow()->IsDone()){
// Game loop.
        game.HandleInput();
        game.Update();
        game.Render();
    }
}