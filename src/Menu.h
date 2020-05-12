#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include <SFML/Graphics.hpp>

namespace sg {

    class Menu {
        private:

            class Implementation;
            Implementation *impl;

        public:

            Menu();
            Menu(const std::vector<std::string> &texts, int posX, int posY, int menuWidth, int menuHeight, int fontSize, sf::Color backgroundColor);

            Menu(const Menu &other);
            Menu& operator=(const Menu &other);


            ~Menu();

            void AddMenuOption(const std::string &text);

            void SetPosition(int posX, int posY);

            void SetWidth(unsigned width);

            void SetHeight(unsigned height);

            std::string GetOptionOverMouse();

            void ProcessInput(sf::RenderWindow* window);

            void Update(sf::RenderWindow* window);

            void Render(sf::RenderTarget* target);

    };

}

#endif // MENU_H_INCLUDED
