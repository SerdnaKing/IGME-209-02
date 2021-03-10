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

//Part 2 global variables (use extern, define in snake.cpp


//introduce the game to the user with instructions for the keys
//creates physics world(b2world) and snake(physics body b2body)
//creates a loop to keep playing until user hits ESC or gets 2 targets

int main() {
	printf("Welcome to Snake game! Press q at any time to quit the game.\nThe controls are WASD to control the direction of the snake.\nYou need to reach the targets location twice in order to win!\n"
		"Press any key, then enter to start the game!");
	

	std::cin >>ch; //dummy user input
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

		do
		{
			if (count >= 2) {
				break; //this will break the loop effectively
			}
			
			update();
			display();
			if (_kbhit() != 0) {
				applyForces();
				if (ch == 'q' || ch == 'Q') {
					break;
			}
			}
			if (fabs((double)body->GetPosition().x - xVal) <= .5 && fabs((double)body->GetPosition().y - yVal) <= .5 && collide == false) {
				collide = true;
				count++;
				xVal = rand()% 10 - 5;
				yVal = rand()% 10 - 5;
				moveTarget(xVal, yVal);
				 collide = false;

			}
		} while (ch != 'q' || count != 2);
	}

