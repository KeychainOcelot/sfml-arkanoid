#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//using 'constexpr' to define immutable compile-time values for resolutions
constexpr int windowWidth{800}, windowHeight{600};

int main()
{
    //Creation of game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid - 1"};
    window.setFramerateLimit(60);

    //Game loop
    while(true)
    {
        //"Clear" the window from previously-drawn graphics
        window.clear(Color::Black);

        //If "escape" is pressed, break out of the loop
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        
        //Show the window contents
        window.display();
    }

    return 0;
}