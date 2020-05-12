#ifndef PAUSEMENUSTATE_H_INCLUDED
#define PAUSEMENUSTATE_H_INCLUDED

#include "GameState.h"
#include "GameEngine.h"
#include "Menu.h"

namespace sg {

    class PauseMenuState: public GameState {
        private:
            static PauseMenuState pauseMenuState;
            Menu *menu;

        protected:
            PauseMenuState() {}

        public:
            void Initialize(GameEngine *game);
            void Update(GameEngine *game);
            void Render(GameEngine *game);
            void ProcessInput(GameEngine *game);

            void Pause();
            void Resume();
            void Cleanup();

            static PauseMenuState* Instance() {
                return &pauseMenuState;
            }



    };

}

#endif // PAUSEMENUSTATE_H_INCLUDED
