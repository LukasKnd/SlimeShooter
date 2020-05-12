#include "./GameEngine.h"

using namespace sg;


GameEngine::GameEngine() {
    isRunning = false;
}


void GameEngine::Initialize(unsigned width, unsigned height) {

    window = new sf::RenderWindow(sf::VideoMode(width, height), "Slime Shooter", sf::Style::Titlebar);
    window->setFramerateLimit(60);

    isRunning = true;
}

void GameEngine::ChangeState(GameState* state)
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Initialize(this);
}

void GameEngine::PushState(GameState* state)
{
	// pause current state
	if ( !states.empty() ) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Initialize(this);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if ( !states.empty() ) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if ( !states.empty() ) {
		states.back()->Resume();
	}
}

void GameEngine::ProcessInput()
{
	// let the state handle events
	states.back()->ProcessInput(this);
}

void GameEngine::Update()
{
	// let the state update the game
	states.back()->Update(this);
}

void GameEngine::Render()
{
    window->clear();

	// let the state draw the screen
	states.back()->Render(this);

	window->display();
}


bool GameEngine::IsRunning() const {
    return isRunning;
}

void GameEngine::Quit() {
    isRunning = false;
}

void GameEngine::Cleanup() {
    window->close();
    delete window;
}




