//
// Created by daniel on 25/01/23.
//

#include "Game.h"
int main(int argc, char* argv[]){
    // Program entry point.
    Game game; // Creating our game object.
    while(!game.GetWindow()->IsDone()){
        // Game loop.
//        game.HandleInput();
        game.Update();
        game.Render();
        //sf::sleep(sf::seconds(0.1)); // Sleep for 0.2 seconds.
        game.RestartClock(); // Restarting our clock.
    }
    return EXIT_SUCCESS;
}