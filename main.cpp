#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//using 'constexpr' to define immutable compile-time values for resolutions
constexpr int windowWidth{800}, windowHeight{600};
constexpr float ballRadius{10.f}, ballVelocity{8.f};

//Class for a ball
struct Ball //struct because we want the implicitly-public things
{
    CircleShape shape; //Create a circle

    Vector2f velocity{-ballVelocity, -ballVelocity};

    //Ball constructor
    //Apply position, radius, color and origin to the shape created from CircleShape
    Ball(float mX, float mY)
    {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(Color::Red);
        shape.setOrigin(ballRadius, ballRadius);
    }
    
    void update()
    {
        shape.move(velocity);

        if(left() < 0) velocity.x = ballVelocity;
        else if(right() > windowWidth) velocity.x = -ballVelocity;

        if(top() < 0) velocity.y = ballVelocity;
        else if(bottom() > windowHeight) velocity.y = -ballVelocity;
    }
    float x() {return shape.getPosition().x;}
    float y() {return shape.getPosition().y;}
    float left() {return x() - shape.getRadius();}
    float right() {return x() + shape.getRadius();}
    float top() {return y() - shape.getRadius();}
    float bottom() {return y() + shape.getRadius();}
};

int main()
{
    //Creation of an instance of a ball
    Ball ball{windowWidth / 2, windowHeight /2};

    //Creation of game window
    RenderWindow window{{windowWidth, windowHeight}, "Arkanoid"};
    window.setFramerateLimit(60);

    //Game loop
    while(true)
    {
        //"Clear" the window from previously-drawn graphics
        window.clear(Color::Black);

        //If "escape" is pressed, break out of the loop
        if(Keyboard::isKeyPressed(Keyboard::Key::Escape)) break;
        
        //Rendering the ball in the window
        ball.update();
        window.draw(ball.shape);
        window.display();
    }

    return 0;
}