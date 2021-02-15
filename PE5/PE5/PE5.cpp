// PE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::RectangleShape myRect(sf::Vector2f(200,150));
    myRect.setFillColor(sf::Color::Green);
    myRect.setPosition(200, 350);
    sf::CircleShape myCircle(50);
    myCircle.setFillColor(sf::Color::Red);
    myCircle.setPosition(60, 60);
    sf::RectangleShape mySquare(sf::Vector2f(80, 80));
    mySquare.setFillColor(sf::Color::Blue);
    mySquare.setPosition(720, 520);
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);


        // draw everything here...
        // window.draw(...);
        window.draw(myRect);
        window.draw(myCircle);
        window.draw(mySquare);
        // end the current frame
        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
