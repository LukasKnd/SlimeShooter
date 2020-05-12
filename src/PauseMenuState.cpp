#include "PauseMenuState.h"
#include "PlayState.h"
#include "MenuState.h"

using namespace sg;

PauseMenuState PauseMenuState::pauseMenuState;


void PauseMenuState::Initialize(GameEngine *game) {

    menu = new Menu(
        std::vector<std::string> {
            "CONTINUE",
            "MAIN MENU"
        },
        WINDOW_WIDTH/2 - WINDOW_WIDTH/4,
        WINDOW_HEIGHT/2 - WINDOW_HEIGHT/4,
        WINDOW_WIDTH/2,
        WINDOW_HEIGHT/2,
        60,
        sf::Color(100,100,100,125)
    );



}
void PauseMenuState::Update(GameEngine *game) {

    menu->Update(game->window);

}
void PauseMenuState::Render(GameEngine *game) {

    PlayState *playState = PlayState::Instance();

    //game->window->clear();

    playState->Render(game);

    game->window->setView(game->window->getDefaultView());

    menu->Render(game->window);

    //game->window->display();

}
void PauseMenuState::ProcessInput(GameEngine *game) {


    sf::Event event;

    game->window->pollEvent(event);

    if (event.type == sf::Event::Closed) {
        game->Quit();
    } else if (event.type == sf::Event::MouseButtonPressed) {

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(menu->GetOptionOverMouse() == "CONTINUE") {
                game->PopState();
            }
            else if(menu->GetOptionOverMouse() == "MAIN MENU") {
                game->PopState();
                game->ChangeState( MenuState::Instance() );
            }

        }

    }


}

void PauseMenuState::Pause() {}
void PauseMenuState::Resume() {}
void PauseMenuState::Cleanup() {
    delete this->menu;
}

