// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//define and include for homework part 2 remember the order of the includes
//may be the reason you encounter some errors in running the application
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include <Box2D.h>
#include <iostream>;
#include "snake.h";
#include <conio.h>;
extern float xVal; //xLoc in the range of -5 to 5
extern float yVal; //yLoc in the range of -5 to 5
int count; //checks to see if target was hit twice.
bool collide = false;
extern int ch;
extern int scoreCount;
//Part 2 global variables (use extern, define in snake.cpp
//extern b2Vec2 TargetLocations[];
extern b2Vec2* currentLocation;
//typedef SHOULD be specific to only Snake.cpp (i believe)
//introduce the game to the user with instructions for the keys
//creates physics world(b2world) and snake(physics body b2body)
//creates a loop to keep playing until user hits ESC or gets 2 targets

int main() {
	printf("Welcome to Snake game!\nThe controls are WASD to control the direction of the snake.\nPress Q to stop all movement and press F to reverse the gravity!\n"
		"You need to reach the targets location in order to win!\n"
		"THE MORE TIME(OUT OF 100 SECONDS) YOU HAVE AT THE END, THE BETTER YOU PERFORMED!\n"
		"Press any key, then enter to start the game!\n");
	
	//printf("");

	//executes loop if input fails
	//executes loop if the input fails (e.g., no characters were read)
	while (std::cout << "Please enter the number of targets you want (up to 10):" && !(std::cin >>ch)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input; please re-enter.\n";
	}
	setupTargets(ch);
	sf::Time maxTime = sf::seconds(100);
	sf::Clock clock;

	
	//open window AFTER getting the numebr from the user
	//introduce the user and tell user about the key presses
	//create the ground body and set the position
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);


	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	//create a ground polygon
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	//create the shape fixture
	groundBody->CreateFixture(&groundBox, 0.0f);

	//code for snake (does it need to be here or should there be 
	b2BodyDef snake;
	snake.type = b2_dynamicBody;
	snake.position.Set(0.0f, 4.0f);
	body = world.CreateBody(&snake);

	//create and attatch a polygon shape
	b2PolygonShape snakeBox;
	snakeBox.SetAsBox(1.0f, 1.0f);

	//create snake fixture definition
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = 1.0f;


	sf::RenderWindow window(sf::VideoMode(900, 700), "My window");
	sf::RectangleShape myTarget(sf::Vector2f(50, 50));
	myTarget.setFillColor(sf::Color::Green);
	myTarget.setPosition(200, 350);
	sf::CircleShape mySnake(25);
	mySnake.setFillColor(sf::Color::Red);
	mySnake.setPosition(60, 60);
	while (window.isOpen()) {
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
		

		b2Vec2 snakeLoc = body->GetPosition();
	    b2Vec2 targetLoc(currentLocation->x, -currentLocation->y);
		mySnake.setPosition((snakeLoc.x + 5) * 80, (-snakeLoc.y + 5) *60);
		myTarget.setPosition((targetLoc.x +5) * 80, 600 -((targetLoc.y + 5) * 60));
		// draw everything here...
	
		window.draw(mySnake);
		window.draw(myTarget);
		// end the current frame
		window.display();
		if (fabs((double)body->GetPosition().x - currentLocation->x) <= .5 && fabs((double)body->GetPosition().y - -currentLocation->y) <= .5 && collide == false) {
			collide = true;
			if (selectNextTarget() == false) {
				window.close();
				sf::Time elapsedTime = clock.getElapsedTime();
				std::cout <<"SCORE:" << maxTime.asSeconds() - elapsedTime.asSeconds() << std::endl;
			}
			else {
				count++;
			}
			 collide = false;

		}
		update();
		processInput();
	}
	}

