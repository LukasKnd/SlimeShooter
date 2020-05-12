#ifndef MENUSTATE_H_INCLUDED
#define MENUSTATE_H_INCLUDED

#include "./GameState.h"
#include "./GameEngine.h"
#include "./Menu.h"

namespace sg {

    class MenuState: public GameState {
        private:
            static MenuState menuState;

            Menu *menu;

        protected:
            MenuState() {}

        public:

            void Initialize(GameEngine *game);
            void Update(GameEngine *game);
            void Render(GameEngine *game);
            void ProcessInput(GameEngine *game);

            void Pause();
            void Resume();
            void Cleanup();

            static MenuState* Instance() {
                return &menuState;
            }



    };

}

#endif // MENUSTATE_H_INCLUDED
