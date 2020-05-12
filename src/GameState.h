#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

namespace sg {

    class GameEngine;

    class GameState {
        public:
            virtual void Initialize(GameEngine *game) = 0;
            virtual void Update(GameEngine *game) = 0;
            virtual void Render(GameEngine *game) = 0;
            virtual void ProcessInput(GameEngine *game) = 0;

            virtual void Pause() = 0;
            virtual void Resume() = 0;
            virtual void Cleanup() = 0;


    };

}

#endif // GAMESTATE_H_INCLUDED
