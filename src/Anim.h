#ifndef ANIM_H_INCLUDED
#define ANIM_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>

namespace sg {

    class Anim {

        private:

            std::vector<sf::Texture*> textures;
            sf::Texture* currentTexture;
            float timeRunning;
            unsigned animSpeed;
            int timesToRun;

        public:

            Anim();

            Anim(const std::vector<sf::Texture*> &textures, unsigned animSpeed, int timesToRun = -1);

            sf::Texture* GetCurrentTexture() const;

            void Update(float deltaTime);

            int CurrentLoopNumber() const;

            void Reset(int timesToRun);

    };

}

#endif // ANIMATION_H_INCLUDED
