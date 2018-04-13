#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <unistd.h>  /// FOR usleep


class Input
{
    public:
        Input(int _x, int _y, int _h, int _w)
        {
            if(!font.loadFromFile("arial.ttf"))
            {
                std::cout<<"ERROR LOADING FONT"<<std::endl;
            }

            InText = "";
            isFocused = false;

            text.setFont(font);
            text.setPosition(_x+5, _y+5);
            text.setCharacterSize(20);

            bgRect = new sf::RectangleShape();
            bgRect->setPosition(_x,_y);
            bgRect->setSize(sf::Vector2f(_h,_w));
            bgRect->setFillColor(sf::Color::Green);

            fgRect = new sf::RectangleShape();
            fgRect->setPosition(_x+5, _y+5);
            fgRect->setSize(sf::Vector2f(_h-10,_w-10));
            fgRect->setFillColor(sf::Color(255,0,0,170)); /// DIFF ALPHA OF RED
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


            if(isFocused == true)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "A" : "a");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "B" : "b");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "C" : "c");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "D" : "d");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "E" : "e");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "F" : "f");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "G" : "g");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "H" : "h");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "I" : "i");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "J" : "g");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "K" : "k");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "L" : "l");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "M" : "m");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "N" : "n");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "O" : "o");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "P" : "p");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Q" : "q");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "R" : "r");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "S" : "s");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "T" : "t");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "U" : "u");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::V)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "V" : "v");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "W" : "w");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "X" : "x");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Y" : "y");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) InText = InText + (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)==true ? "Z" : "z");
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) InText = InText + ".";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) InText = InText + " ";
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))  InText = InText + "0";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))  InText = InText + "1";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))  InText = InText + "2";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))  InText = InText + "3";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))  InText = InText + "4";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))  InText = InText + "5";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))  InText = InText + "6";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))  InText = InText + "7";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))  InText = InText + "8";
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))  InText = InText + "9";


                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
                {
                    if(user_data != nullptr) this->runCallback();

                    this->changeFocus(false);
                    ///std::cout<<InText<<std::endl; DEBUG
                }
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
                {
                    InText = InText.substr(0, InText.size()-1);
                }

                text.setString(InText);

                usleep(68000);
            }



            app.draw(*bgRect);
            app.draw(*fgRect);
            app.draw(text);
        }

        void changeFocus(bool input)
        {
            isFocused = input;
            fgRect->setFillColor( (input == true ? sf::Color::Red : sf::Color(255,0,0,170)) ); /// sf::Color(255,0,0,170) - change alpha of red color
        }

        /// HARD CODE
        void setCallback(void (*_f)(void* p), void* _p = (void*)1)
        {
            user_data = _p;

            ptrFunc = _f;
        }
        ///END

        std::string getText() { return InText; }

    private:
        std::string InText;

        sf::RectangleShape* fgRect;
        sf::RectangleShape* bgRect;
        sf::Font font;
        sf::Text text;

        bool isFocused;

        /// user_data for keep data and send it to linked callback
        void* user_data;
        void (*ptrFunc)(void*);  /// variable, that keeps pointer for function( with parameter void*)

        void runCallback()
        {
            this->ptrFunc(user_data);
        }
};

#endif // INPUT_H
