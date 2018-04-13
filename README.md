_It's true, I'm a Rubik's, a beautiful mess\
At times juvenile, yes, I goof and I jest\
A flawed human, I guess\
But I'm doin' my best to not ruin your expectations and meet 'em_\
__@ Eminem - Walk On Water__

_If you want something to work well, do it yourself_\
__@ Me while searching the GUI__

# Handmade Graphical User Interface for SFML

It's first time I try to create useful GUI for SFML. I have created the basic widgets such as `Button`, `Input` and `Label`.
They all can be containered in `Frame` to  update them in one function use. But for containing them inside `Frame` You need use special functions of adding according to type of widget.

# Docs:

  - *Button*\
    Button(int _x, int _y, int _h, int _w, std::string _text) --- constructor\
    void setTexture(std::string dir) --- set image of background\
    void setCharacterSize(unsigned int _size)\
    void checkPress(sf::Vector2f click) --- check if button was pressed, if true - runs callback\
    =========================================\
    default functions for changing dimensions\
    getter functions\
    =========================================\
    void setCallback(void (*_f)(void* p), void* _p) --- first argument - name of func to chain with callback, second argument - pointer to some data\
      [ Code snippet for creating callbacks ] - *we want to output string*\
        void callback(void* p)\
        {\
            string* str = (string*) p;\
            cout<<*str<<endl;\
        }
        
    void update(sf::RenderWindow& app) --- speaks for itself
    
   - *Label*\
      =========================================\
      default functions for changing dimensions\
      getter functions\
      =========================================\
      
      void setString(std::string _text) --- sets the text diplayed on screen\
      void setColor(sf::Color c) --- no need to explain\
      void setCharacterSize(unsigned int _size) --- as You see...\
      void update(sf::RenderWindow& app) --- no comments
    
    - *Input*\
      =========================================\
      default functions for changing dimensions\
      getter functions\
      =========================================\
      
      void setColor(sf::Color& fgColor, sf::Color& bgColor) --- sets the color of frame and main field\
      void checkFocus(sf::Vector2f click) --- checks if click was in the field\
      void update(sf::RenderWindow& app) --- see upper\
      void setCallback(void (*_f)(void* p), void* _p = (void*)1) --- sets callback when You press `Enter`(`Return`), by default you can not set the user data(set argument): by defalut NOT EQUALS ZERO, if you call this func. If you don't need the callback by pressing `Enter`, leave this function alone.\
      std::string getText() --- return current text
     
    - *Frame*
    
      void addButton(Button* b)   --- add button\
      void addLabel(Label* l)     --- add label\
      void addInput(Input* i)     --- add input\
      void makeBackGround(string dir) --- set the image as background\
      void updateWidgets(sf::RenderWindow& app) --- update all widgets
      
      Button* getButton(int pos) --- grab button by pos in vector\
      Label* getLabel(int pos)   --- grab label by pos in vector\
      Input* getInput(int pos)   --- grab input by pos in vector
      
 Using `frame.updateWidgets()` in loop between `app.clear()` and `app.display`.
 
 ASAP I'll add composition files based on `Lua`, possibility to creating and loading them to create the GUI. 
 
