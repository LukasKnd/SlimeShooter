#ifndef PLAYSTATE_H_INCLUDED
#define PLAYSTATE_H_INCLUDED

#include "./GameEngine.h"
#include "./GameState.h"
#include "./EntityManager.h"
#include "./AssetManager.h"
#include "./SlimeSpawnManager.h"

namespace sg {

    class PlayState: public GameState {
        private:
            static PlayState playState;
            sf::Clock timeLastFrame;
            sf::View *view;
        protected:
            PlayState() {}

        public:

            static sf::RenderWindow *window;
            static float timeRunning;
            static EntityManager* manager;
            static AssetManager* assetManager;
            static SlimeSpawnManager* slimeSpwnManager;

            void Initialize(GameEngine *game);
            void Update(GameEngine *game);
            void Render(GameEngine *game);
            void ProcessInput(GameEngine *game);
            void LoadLevel();

            void Pause();
            void Resume();
            void Cleanup();

            static PlayState* Instance() {
                return &playState;
            }



    };

}

#endif // PLAYSTATE_H_INCLUDED
