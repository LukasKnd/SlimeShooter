#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

namespace sg {

    class Entity;

    class Component {
        protected:
            Component() {}

        public:
            Entity* owner;
            virtual ~Component() {}
            virtual void Initialize() {}
            virtual void Update(float deltaTime) {}
            virtual void Render() {}

    };

}

#endif // COMPONENT_H_INCLUDED
