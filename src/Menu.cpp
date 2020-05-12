#include "./Menu.h"

using namespace sg;

class Menu::Implementation {
    private:
        sf::Font font;
        std::vector<sf::Text> texts;
        int fontSize;
        int posX;
        int posY;
        int menuWidth;
        int menuHeight;
        sf::Color backgroundColor;
        sf::RectangleShape background;
        std::string mouseOverOption;

        void setAll() {

            int totalTextHeight = fontSize * texts.size() + 10 * texts.size();
            int textStartY = posY + menuHeight / 2 - totalTextHeight / 2;


            for(int i = 0; i < texts.size(); i++) {
                this->texts[i].setCharacterSize(fontSize);
                this->texts[i].setPosition( sf::Vector2f(menuWidth/2 - this->texts[i].getGlobalBounds().width/2 + posX, textStartY + i * fontSize + i * 10) );
            }

            background.setSize( sf::Vector2f(menuWidth, menuHeight) );
            background.setPosition(posX, posY);
            background.setFillColor( backgroundColor );

        }

    public:

        ~Implementation() {}

        Implementation(const std::vector<std::string> &texts, int posX, int posY, int menuWidth, int menuHeight, int fontSize, sf::Color backgroundColor) {
            this->fontSize = fontSize;
            this->posX = posX;
            this->posY = posY;
            this->menuWidth = menuWidth;
            this->menuHeight = menuHeight;
            this->backgroundColor = backgroundColor;

            font.loadFromFile("./assets/fonts/Arial.ttf");

            for(int i = 0; i < texts.size(); i++) {
                this->texts.push_back( sf::Text(texts[i], font, fontSize) );
            }

            setAll();
        }

        void AddMenuOption(const std::string &text) {
            texts.push_back(sf::Text(text, font, fontSize));

            setAll();
        }

        void SetPosition(int posX, int posY) {
            this->posX = posX;
            this->posY = posY;

            setAll();

        }

        void SetWidth(unsigned width) {
            menuWidth = width;

            setAll();

        }

        void SetHeight(unsigned height) {
            menuHeight = height;

            setAll();
        }

        std::string GetOptionOverMouse() {
            return mouseOverOption;
        }


        void ProcessInput(sf::RenderWindow* window) {

        }


        void Update(sf::RenderWindow* window) {

            sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);
            sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);

            bool optionSet = false;

            for(auto& text: texts) {
                if(text.getGlobalBounds().contains(worldPos)) {
                    optionSet = true;
                    text.setColor(sf::Color::Red);
                    mouseOverOption = text.getString();
                } else {
                    text.setColor(sf::Color::White);
                }
            }

            if(optionSet == false) {
                mouseOverOption = "";
            }

        }

        void Render(sf::RenderTarget* target) {
            target->draw(background);
            for(sf::Text& text: texts) {
                target->draw(text);
            }
        }

};


Menu::Menu() : Menu(std::vector<std::string>{}, 0, 0, 0, 0, 30, sf::Color::Black) {

}

Menu::Menu(const std::vector<std::string> &texts, int posX, int posY, int menuWidth, int menuHeight, int fontSize, sf::Color backgroundColor)
    : impl(new Implementation(texts, posX, posY, menuWidth, menuHeight, fontSize, backgroundColor)) {

}

Menu::~Menu() {
    delete impl;
}

Menu::Menu(const Menu &other) : impl(new Implementation(*other.impl)) {

}

Menu& Menu::operator=(const Menu &other) {
    *this->impl = *other.impl;
    return *this;
}

void Menu::AddMenuOption(const std::string &text) {
    impl->AddMenuOption(text);
}

void Menu::SetPosition(int posX, int posY) {
    impl->SetPosition(posX, posY);
}

void Menu::SetWidth(unsigned width) {
    impl->SetWidth(width);
}

void Menu::SetHeight(unsigned height) {
    impl->SetHeight(height);
}

std::string Menu::GetOptionOverMouse() {
    return impl->GetOptionOverMouse();
}

void Menu::ProcessInput(sf::RenderWindow* window) {

}

void Menu::Update(sf::RenderWindow* window) {
    impl->Update(window);
}

void Menu::Render(sf::RenderTarget* target) {
    impl->Render(target);
}



