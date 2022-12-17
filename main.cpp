#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//using 'constexpr' to define immutable compile-time values for resolutions
constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f};

//Class for a ball
struct Ball //struct because we want the implicitly-public things
{
    CircleShape shape; //Create a circle

    //Ball constructor
    //Apply position, radius, color and origin to the shape created from CircleShape
    Ball(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }
};

int main()
{
    //Creation of an instance of a ball
    Ball ball{windowWidth / 2, windowHeight /2};

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
        
        //Rendering the ball in the window
        window.draw(ball.shape);
        window.display();
    }

    return 0;
}