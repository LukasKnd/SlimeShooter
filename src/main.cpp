
//#include "./PlayState.h"
#include <iostream>
#include "./GameEngine.h"
#include "./PlayState.h"
#include "./MenuState.h"

using namespace sg;
int main(int argc, char *args[]) {

    try {

        GameEngine game;

        game.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

        game.ChangeState( MenuState::Instance() );

        while(game.IsRunning()) {
            game.ProcessInput();
            game.Update();
            game.Render();
        }

        game.Cleanup();

    } catch(std::exception &e) {
        std::cerr << "EXCEPTION CAUGHT WHAT: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << "UNKNOW EXCEPTION CAUGHT" << std::endl;
    }




	return 0;

}

