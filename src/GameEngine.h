#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>
#include "./GameState.h"
#include "./Constants.h"

namespace sg {

    class GameEngine {

        private:
            std::vector<GameState*> states;
            bool isRunning;


        public:

            GameEngine();

            GameEngine(const GameEngine &other) = delete;
            GameEngine& operator=(const GameEngine &other) = delete;

            sf::RenderWindow* window;

            void ChangeState(GameState* state);
            void PushState(GameState* state);
            void PopState();

            bool IsRunning() const;

            void Quit();

            void Initialize(unsigned width, unsigned height);
            void ProcessInput();
            void Update();
            void Render();
            void Cleanup();

    };

}

#endif // GAMEENGINE_H_INCLUDED
