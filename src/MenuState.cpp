#include "./MenuState.h"
#include "./PlayState.h"

using namespace sg;

MenuState MenuState::menuState;


void MenuState::Initialize(GameEngine *game) {

    menu = new Menu(
        std::vector<std::string> {
            "PLAY",
            "EXIT"
        },
        WINDOW_WIDTH/2 - WINDOW_WIDTH/4,
        WINDOW_HEIGHT/2 - WINDOW_HEIGHT/4,
        WINDOW_WIDTH/2,
        WINDOW_HEIGHT/2,
        60,
        sf::Color::Black
    );




}
void MenuState::Update(GameEngine *game) {

    menu->Update(game->window);

}
void MenuState::Render(GameEngine *game) {

    //game->window->clear();

    menu->Render(game->window);

    //game->window->display();

}
void MenuState::ProcessInput(GameEngine *game) {

    sf::Event event;

    game->window->pollEvent(event);

    if (event.type == sf::Event::Closed) {
        game->Quit();
    } else if (event.type == sf::Event::MouseButtonPressed) {

        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(menu->GetOptionOverMouse() == "PLAY") {
                game->ChangeState( PlayState::Instance() );
            } else if (menu->GetOptionOverMouse() == "EXIT") {
                game->Quit();
            }

        }

    }


}

void MenuState::Pause() {}
void MenuState::Resume() {}
void MenuState::Cleanup() {

    delete menu;

}
