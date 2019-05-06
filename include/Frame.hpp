#ifndef FRAME_H
#define FRAME_H

#include "Button.hpp"
#include "Label.hpp"
#include "Input.hpp"
#include "LuaScript.hpp"

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

        void loadFrameFromFile(string dir, string currentFrame)
        {
            LuaScript lua;
            lua.ScriptInit(dir);

            for(int countWidgets = 1; countWidgets <= lua.getTableVar<int>(currentFrame, "countWidgets"); countWidgets++)
            {
                string currentWidget = "widget"+toString<int>(countWidgets); /// For easier coding and reading

                int x = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "x");
                int y = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "y");
                string typeOfWidget = lua.getVarFromTableInTable<string>(currentFrame,currentWidget, "typeOfWidget");

                if(typeOfWidget == "button")
                {
                    int h = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "h");
                    int w = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "w");
                    string text = lua.getVarFromTableInTable<string>(currentFrame,currentWidget, "text");

                    Button* but = new Button(x,y,h,w,text);
                    buttons.push_back(but);
                }
                else if(typeOfWidget == "input")
                {
                    int h = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "h");
                    int w = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "w");

                    Input* in = new Input(x,y,h,w);
                    inputs.push_back(in);
                }
                else if(typeOfWidget == "label")
                {
                    string text = lua.getVarFromTableInTable<string>(currentFrame,currentWidget, "text");
                    int characterSize = lua.getVarFromTableInTable<int>(currentFrame,currentWidget, "characterSize");

                    Label* label = new Label(x,y,text);
                    label->setCharacterSize(characterSize);
                    labels.push_back(label);
                }
            }

            lua.CloseScript();
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
