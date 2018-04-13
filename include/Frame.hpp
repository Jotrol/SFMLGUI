#ifndef FRAME_H
#define FRAME_H

#include "Button.h"
#include "Label.hpp"
#include "Input.hpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Frame
{
    public:

        void addButton(Button* b) { buttons.push_back(b); }
        void addLabel(Label* l) { labels.push_back(l); }
        void addInput(Input* i) { inputs.push_back(i); }

        void makeBackGround(string dir)
        {
            texture = new sf::Texture();
            if(!texture->loadFromFile(dir))
            {
                cout<<"ERROR LOADING TEXTURE"<<endl;
            }
            backGround.setTexture(*texture);
        }

        void updateWidgets(sf::RenderWindow& app)
        {
            app.draw(backGround);

            for(auto it = buttons.begin(); it!=buttons.end(); ++it)
                (*it)->update(app);
            for(auto it = labels.begin(); it!=labels.end(); ++it)
                (*it)->update(app);
            for(auto it = inputs.begin(); it!=inputs.end(); ++it)
                (*it)->update(app);
        }

        Button* getButton(int pos)  { return buttons[pos]; }
        Label* getLabel(int pos) { return labels[pos]; }
        Input* getInput(int pos) { return inputs[pos]; }

    private:

        vector<Label*> labels;
        vector<Button*> buttons;
        vector<Input*> inputs;

        sf::Sprite backGround;
        sf::Texture* texture;

};

#endif // FRAME_H
