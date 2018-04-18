#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <unistd.h>  /// FOR usleep


class Input
{
    public:
        Input(float _x, float _y, int _h, int _w)
        {
            if(!font.loadFromFile("arial.ttf"))
            {
                std::cout<<"ERROR LOADING FONT"<<std::endl;
            }

            InText = "";
            isFocused = false;

            text.setFont(font);
            text.setPosition(_x+5, _y+2);
            text.setCharacterSize(20);

            bgRect = new sf::RectangleShape(sf::Vector2f(_w,_h));
            bgRect->setPosition(_x,_y);
            bgRect->setFillColor(sf::Color::Green);

            fgRect = new sf::RectangleShape(sf::Vector2f(_w-10,_h-10));
            fgRect->setPosition(_x+5, _y+5);
            fgRect->setFillColor(sf::Color(255,0,0,170)); /// DIFF ALPHA OF RED

            user_data = nullptr;  /// DON'T WORRY - IF YOU SET CALLBACK IT'LL WORK PERFECTLY; IT'LL REWRITE ADRESS OR SOMETHING LIKE THAT
        }

        void setColor(sf::Color& fgColor, sf::Color& bgColor)
        {
            fgRect->setFillColor(fgColor);
            bgRect->setFillColor(bgColor);
        }

        void setCharacterSize(unsigned int _size)
        {
            text.setCharacterSize(_size);
        }

        void checkFocus(sf::Vector2f click)
        {
            if(fgRect->getGlobalBounds().contains(click) == true)
            {
                this->changeFocus(true);
                ///std::cout<<"FOCUSED"<<std::endl;     DEBUG
            }
            else
            {
                this->changeFocus(false);
                ///std::cout<<"UNFOCUSED"<<std::endl;  DEBUG
            }
        }

        void update(sf::RenderWindow& app)   /// REMAKE INPUT FUNCTION OF INPUT
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                this->checkFocus(MousePos(app));
            }

            app.draw(*bgRect);
            app.draw(*fgRect);
            app.draw(text);
        }
        void handleEvent(sf::RenderWindow& app, sf::Event e)
        {
            if(isFocused == true && e.type == sf::Event::KeyReleased)
            {

                     if(e.key.code == sf::Keyboard::A) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "A" : "a");
                else if(e.key.code == sf::Keyboard::B) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "B" : "b");
                else if(e.key.code == sf::Keyboard::C) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "C" : "c");
                else if(e.key.code == sf::Keyboard::D) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "D" : "d");
                else if(e.key.code == sf::Keyboard::E) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "E" : "e");
                else if(e.key.code == sf::Keyboard::F) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "F" : "f");
                else if(e.key.code == sf::Keyboard::G) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "G" : "g");
                else if(e.key.code == sf::Keyboard::H) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "H" : "h");
                else if(e.key.code == sf::Keyboard::I) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "I" : "i");
                else if(e.key.code == sf::Keyboard::J) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "J" : "g");
                else if(e.key.code == sf::Keyboard::K) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "K" : "k");
                else if(e.key.code == sf::Keyboard::L) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "L" : "l");
                else if(e.key.code == sf::Keyboard::M) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "M" : "m");
                else if(e.key.code == sf::Keyboard::N) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "N" : "n");
                else if(e.key.code == sf::Keyboard::O) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "O" : "o");
                else if(e.key.code == sf::Keyboard::P) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "P" : "p");
                else if(e.key.code == sf::Keyboard::Q) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Q" : "q");
                else if(e.key.code == sf::Keyboard::R) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "R" : "r");
                else if(e.key.code == sf::Keyboard::S) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "S" : "s");
                else if(e.key.code == sf::Keyboard::T) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "T" : "t");
                else if(e.key.code == sf::Keyboard::U) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "U" : "u");
                else if(e.key.code == sf::Keyboard::V) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "V" : "v");
                else if(e.key.code == sf::Keyboard::W) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "W" : "w");
                else if(e.key.code == sf::Keyboard::X) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "X" : "x");
                else if(e.key.code == sf::Keyboard::Y) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Y" : "y");
                else if(e.key.code == sf::Keyboard::Z) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Z" : "z");

                     if(e.key.code == sf::Keyboard::Quote) InText = InText + "'";
                else if(e.key.code == sf::Keyboard::Period) InText = InText + ".";
                else if(e.key.code == sf::Keyboard::Comma)  InText = InText + ",";
                else if(e.key.code == sf::Keyboard::Space) InText = InText + " ";

                     if(e.key.code == sf::Keyboard::Num0)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? ")" : "0");
                else if(e.key.code == sf::Keyboard::Num1)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "!" : "1");
                else if(e.key.code == sf::Keyboard::Num2)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "@" : "2");
                else if(e.key.code == sf::Keyboard::Num3)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "#" : "3");
                else if(e.key.code == sf::Keyboard::Num4)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "$" : "4");
                else if(e.key.code == sf::Keyboard::Num5)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "%" : "5");
                else if(e.key.code == sf::Keyboard::Num6)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "^" : "6");
                else if(e.key.code == sf::Keyboard::Num7)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "&" : "7");
                else if(e.key.code == sf::Keyboard::Num8)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "*" : "8");
                else if(e.key.code == sf::Keyboard::Num9)  InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "(" : "9");

                if(e.key.code == sf::Keyboard::Return)
                {
                    if(user_data != nullptr) this->runCallback();

                    this->changeFocus(false);
                    ///std::cout<<InText<<std::endl; DEBUG
                }
                else if(e.key.code == sf::Keyboard::BackSpace)
                {
                    InText = InText.substr(0, InText.size()-1);
                }

                text.setString(InText);

                //usleep(69000);  /// Experimental value
            }
        }



        /// HARD CODE
        void setCallback(void (*_f)(void* p), void* _p = (void*)1)
        {
            user_data = _p;

            ptrFunc = _f;
        }
        ///END

        std::string getText() { return InText; }
        void setText(std::string _text) { InText = _text; }

    private:
        std::string InText;

        sf::RectangleShape* fgRect;
        sf::RectangleShape* bgRect;
        sf::Font font;
        sf::Text text;

        bool isFocused;

        void changeFocus(bool input)
        {
            isFocused = input;
            fgRect->setFillColor( (input == true ? sf::Color::Red : sf::Color(255,0,0,170)) ); /// sf::Color(255,0,0,170) - change alpha of red color
        }

        /// user_data for keep data and send it to linked callback
        void* user_data;
        void (*ptrFunc)(void*);  /// variable, that keeps pointer for function( with parameter void*)

        void runCallback()
        {
            this->ptrFunc(user_data);
        }
};

#endif // INPUT_H
