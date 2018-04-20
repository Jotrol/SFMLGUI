#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include <fstream>
#include "LuaScript.hpp"
#include "Frame.hpp"

using namespace std;

class Widget
{
    public:

        sf::RectangleShape* rect;
        sf::Texture* texture;
        sf::Font font;
        sf::Text text;

        string type;
        string textInside;
        string pathOfTexture;

        Widget(int _x, int _y, string _type, string _textInside, int _h = 0, int _w = 0, string path = "", int charSize = 14)
        {
            rect = new sf::RectangleShape();
            rect->setPosition(_x, _y);

            type = _type;
            textInside = _textInside;
            pathOfTexture = path;

            rect->setSize(sf::Vector2f(_w,_h));

            font.loadFromFile("arial.ttf");

            text.setFont(font);
            text.setPosition(_x+5, _y + 5);
            text.setFillColor( (type == "label") ? (sf::Color::White) : (sf::Color::Black) );
            text.setCharacterSize(charSize);

            if( type == "label") rect->setSize( sf::Vector2f( textInside.size() * text.getCharacterSize(), text.getCharacterSize() + 30 ));
            if( type != "label" )   rect->setFillColor(sf::Color::White);

            text.setString( string(type + "\n" + textInside));

            if(path != "")
            {
                texture = new sf::Texture();

                if(!texture->loadFromFile(path))
                {
                    std::cout<<"ERROR LOADING TEXTURE IN: "<<path<<std::endl;
                }

                rect->setTexture(texture);
            }
        }

        void checkFocus(sf::Vector2f mousePos)
        {
            if( rect->getGlobalBounds().contains(mousePos) == true)
            {
                sf::Vector2f newPos( mousePos.x - rect->getGlobalBounds().width / 4, mousePos.y - rect->getGlobalBounds().height / 4);

                rect->setPosition(newPos);

                text.setString( string( toString<int>(newPos.x) + " : " + toString<int>(newPos.y) ) );
                text.setPosition(rect->getPosition().x + 5, rect->getPosition().y + 5);
            }
            else if( rect->getGlobalBounds().contains(mousePos) == false)
            {
                text.setString( string(type + " :\n" + textInside));
            }
        }

        void update(sf::RenderWindow& app)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) checkFocus(MousePos(app));

            if(type != "label")  app.draw(*rect);
            if(type != "input" ) app.draw(text);
        }

};

class Field
{
    public:
        Field() { }

        void createWidget(int _x, int _y, string _type, string _textInside, int _h = 0, int _w = 0, string path = "", int charSize = 14)
        {
            widgets.push_back(new Widget(_x,_y,_type,_textInside,_h,_w, path, charSize));
        }

        void update(sf::RenderWindow& app)
        {
            for(auto it = widgets.begin(); it != widgets.end(); ++it)
            {
                (*it)->update(app);
            }
        }

        void makeFile(string nameOfFile)
        {
            ofstream file(nameOfFile + ".lua");

            file<<"frame = {"<< '\n' << '\t' <<"countWidgets = "<<widgets.size()<<"," << '\n';

            for(unsigned int i = 0; i<widgets.size(); i++)
            {
                file<< '\t' <<"widget"<<i<<" = { x = "<<(int)(widgets.at(i)->rect->getPosition().x)<<", ";       /// x position
                file<<"y = "<<(int)(widgets.at(i)->rect->getPosition().y - 70)<<", ";                   /// y position; offset 70 because GUI on the top
                file<<"typeOfWidget = " << '"' << widgets.at(i)->type << '"' << ", ";     /// typeOfWidget

                if(widgets.at(i)->type != "label")
                {
                    file<<"h = "<<widgets.at(i)->rect->getGlobalBounds().height << ", ";    /// h size
                    file<<"w = "<<widgets.at(i)->rect->getGlobalBounds().width << ", ";     /// w size
                    if(widgets.at(i)->type == "button")
                    {
                        file<<"path = \""<<widgets.at(i)->pathOfTexture<<"\", ";
                    }
                }

                file<<"characterSize = " << widgets.at(i)->text.getCharacterSize() <<" ,";

                if( i != widgets.size()-1)
                {
                    file<<"text = \""<<widgets.at(i)->textInside << "\"},"<<'\n';                     /// text: if it's not end
                }
                else
                {
                    file<<"text = \""<<widgets.at(i)->textInside << "\"}\n}";                     /// text: if it's last, not comma, closing of frame
                }
            }
        }

        void clearField() { widgets.clear(); }

    private:

        vector<Widget*> widgets;

};

#endif // FIELD_H
