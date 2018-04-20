#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <iostream>

sf::Vector2f MousePos(sf::RenderWindow& app)
{
    sf::Vector2i raw_pos = sf::Mouse::getPosition(app);
    sf::Vector2f pos = app.mapPixelToCoords(raw_pos);

    return pos;
}

class Button
{
    public:
        Button(float _x, float _y, int _h, int _w, std::string _text)
        {
            rect = new sf::RectangleShape(sf::Vector2f(_w,_h));
            rect->setPosition(sf::Vector2f(_x, _y));

            if(!font.loadFromFile("arial.ttf"))
            {
                std::cout<<"ERROR LOADING FONT"<<std::endl;
            }

            text.setFont(font);
            text.setString(_text);

            sf::Vector2f posText( rect->getPosition().x + rect->getGlobalBounds().width/4, rect->getPosition().y + rect->getGlobalBounds().height/4);
            text.setPosition(posText);

            /// DEFAULT
            text.setCharacterSize(14);
            text.setColor(sf::Color::Black);

            user_data = nullptr;   /// DON'T WORRY - IF YOU SET CALLBACK IT'LL WORK PERFECTLY; IT'LL REWRITE ADRESS OR SOMETHING LIKE THAT
        }

        void setTexture(std::string dir)
        {
            texture = new sf::Texture();

            if(!texture->loadFromFile(dir))
            {
                std::cout<<"ERROR LOADING TEXTURE IN: "<<dir<<std::endl;
            }

            rect->setTexture(texture);

            pathForTexture = dir;
        }

        void setCharacterSize(unsigned int _size)
        {
            text.setCharacterSize(_size);
        }

        void checkPress(sf::Vector2f click)
        {
            if(rect->getGlobalBounds().contains(click) == true)
            {
                this->runCallback();

                return;
            }
            else
            {
                return;
            }
        }


        void setPosition(int _x, int _y)
        {
            rect->setPosition(sf::Vector2f(_x, _y));
        }

        void setSize(int _h, int _w)
        {
            rect->setSize(sf::Vector2f(_w, _h));
        }

        void setColor(sf::Color c)
        {
            rect->setFillColor(c);
        }
        void setTextColor(sf::Color c)
        {
            text.setFillColor(c);
        }

        sf::Vector2f  getPosition() { return rect->getPosition(); }
        sf::Vector2f getSize()  { return rect->getSize(); }



        /// HARD CODE
        void setCallback(void (*_f)(void* p), void* _p)
        {
            user_data = _p;

            ptrFunc = _f;
        }
        ///END

        void update(sf::RenderWindow& app)
        {
            app.draw(*rect);
            app.draw(text);
        }
        void handleEvent(sf::RenderWindow& app, sf::Event e)
        {
            if(e.type == sf::Event::MouseButtonReleased && e.key.code == sf::Mouse::Left && user_data != nullptr) this->checkPress(MousePos(app));

        }

        int getCharacterSize() { return text.getCharacterSize(); }


    private:

        void runCallback()
        {
            this->ptrFunc(user_data);
        }

        sf::Font font;
        sf::Text text;

        std::string pathForTexture;  /// need to be saved in file
        sf::Texture* texture;
        sf::RectangleShape* rect;

        /// user_data for keep data and send it to linked callback
        void* user_data;
        void (*ptrFunc)(void*);  /// variable, that keeps pointer for function( with parameter void*)

};

#endif // BUTTON_H
