#ifndef LABEL_H
#define LABEL_H

#include <string>
#include <iostream>

class Label
{
    public:
        Label(int _x, int _y, std::string _text)
        {

            if(!font.loadFromFile("arial.ttf"))
            {
                std::cout<<"ERROR LOADING FONT"<<std::endl;
            }

            text.setFont(font);
            text.setString(_text);
            text.setPosition(_x, _y);

        }

        void setPosition(int _x, int _y)
        {
            text.setPosition(_x, _y);
        }

        void setColor(sf::Color c)
        {
            text.setFillColor(c);
        }

        void setCharacterSize(unsigned int _size)
        {
            text.setCharacterSize(_size);
        }

        void setString(std::string _text)
        {
            text.setString(_text);
        }

        void update(sf::RenderWindow& app)
        {
            app.draw(text);
        }

        sf::Vector2f getPosition() { return text.getPosition(); }

    private:

        sf::Font font;
        sf::Text text;
};

#endif // LABEL_H
