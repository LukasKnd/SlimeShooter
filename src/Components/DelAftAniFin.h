#ifndef DELAFTANIFIN_H_INCLUDED
#define DELAFTANIFIN_H_INCLUDED

#include <iostream>
#include <functional>

#include "./SpriteComponent.h"

namespace sg {

    class DelAftAniFin: public Component {
        private:

            SpriteComponent* spriteComponent;
            std::string aniName;
            std::function<void()> AfterAniFinish;

        public:

            DelAftAniFin(const DelAftAniFin &other) = delete;
            DelAftAniFin& operator=(const DelAftAniFin &other) = delete;

            DelAftAniFin(std::string aniName, std::function<void()> AfterAniFinish = []()->void{}) : aniName(aniName) {
                this->AfterAniFinish = AfterAniFinish;
            }

            void Initialize() override {
                spriteComponent = owner->GetComponent<SpriteComponent>();
                spriteComponent->SetAnimationName(aniName);
            }

            void Update(float deltaTime) override {
                if(spriteComponent->GetCurrentSprite()->CurrentLoopNumber()) {
                    owner->Destroy();
                    AfterAniFinish();
                }
            }


    };

}

#endif // DELAFTANIFIN_H_INCLUDED
