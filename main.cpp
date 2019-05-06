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
    Frame* frame1 = (Frame*) p;

    frame1->makeBackGround(frame1->getInput(0)->getText());
}

int main()
{
    sf::RenderWindow app(sf::VideoMode(800, 600), "GUI TEST");

    Frame frame1;

    Input in(100,100,100,50);
    Label label(20,20,"TEXT");
    Button button(250,250,100,40,"ITS BUTTON");
        button.setCallback(cb, &frame1);

    frame1.addButton(&button);
    frame1.addLabel(&label);
    frame1.addInput(&in);

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();


        }

        app.clear();

        frame1.updateWidgets(app);

        app.display();
    }

    return EXIT_SUCCESS;
}
