#ifndef BUTTON_H
#define BUTTON_H

#include <string>

sf::Vector2f MousePos(sf::RenderWindow& app)
{
    sf::Vector2i raw_pos = sf::Mouse::getPosition(app);
    sf::Vector2f pos = app.mapPixelToCoords(raw_pos);

    return pos;
}

class Button
{
    public:
        Button(int _x, int _y, int _h, int _w, std::string _text)
        {
            rect = new sf::RectangleShape(sf::Vector2f(_h,_w));
            rect->setPosition(sf::Vector2f(_x, _y));

            if(!font.loadFromFile("arial.ttf"))
            {
                std::cout<<"ERROR LOADING FONT"<<std::endl;
            }

            text.setFont(font);
            text.setString(_text);
            text.setPosition(sf::Vector2f(rect->getPosition()));

            /// DEFAULT
            text.setCharacterSize(14);
            text.setColor(sf::Color::Black);

        }

        void setTexture(std::string dir)
        {
            texture = new sf::Texture();

            if(!texture->loadFromFile(dir))
            {
                std::cout<<"ERROR LOADING TEXTURE IN: "<<dir<<std::endl;
            }

            rect->setTexture(texture);
        }

        void setCharacterSize(unsigned int _size)
        {
            text.setCharacterSize(_size);
        }

        void checkPress(sf::Vector2f click)
        {
            if(rect->getGlobalBounds().contains(click))
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
            rect->setSize(sf::Vector2f(_h, _w));
        }

        void setColor(sf::Color c)
        {
            rect->setFillColor(c);
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

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) this->checkPress(MousePos(app));
        }


    private:

        void runCallback()
        {
            this->ptrFunc(user_data);
        }

        sf::Font font;
        sf::Text text;

        sf::Texture* texture;
        sf::RectangleShape* rect;

        /// user_data for keep data and send it to linked callback
        void* user_data;
        void (*ptrFunc)(void*);  /// variable, that keeps pointer for function( with parameter void*)

};

#endif // BUTTON_H
