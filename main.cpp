#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <vector>

#include "Frame.hpp"
#include "Input.hpp"

using namespace std;

/*sf::Vector2f MousePos(sf::RenderWindow& app)
{
    sf::Vector2i raw_pos = sf::Mouse::getPosition(app);
    sf::Vector2f pos = app.mapPixelToCoords(raw_pos);

    return pos;
}*/

void cb(void* p)
{
    Input* in = (Input*) p;

    cout<<in->getText()<<endl;
}

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "GUI TEST");

    Frame frame1;
    Frame frame2;

    Frame outFrame;  /// FOR SWITCHING SCENES

    frame1.loadFrameFromFile("frames.lua", "frame1");
        frame1.getButton(0)->setCallback(cb, frame1.getInput(0));
    frame2.loadFrameFromFile("frames.lua", "frame2");
        frame2.getButton(0)->setCallback(cb, frame2.getInput(0));
        frame2.getInput(1)->setCallback(cb, frame2.getInput(1));
        frame2.getInput(2)->setCallback(cb, frame2.getInput(2));


    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();


        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) outFrame = frame1; /// CHANGING SCENES BY BUTTONS 1 AND 2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) outFrame = frame2;

        app.clear();

        outFrame.updateWidgets(app);

        app.display();
    }

    return EXIT_SUCCESS;
}
