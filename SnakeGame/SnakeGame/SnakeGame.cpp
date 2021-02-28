// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//#include <iostream>
#include <Box2D.h>
#include "snake.h";
#include <conio.h>;
//#include "Snake.cpp";

//introduce the game to the user with instructions for the keys
//creates physics world(b2world) and snake(physics body b2body)
//creates a loop to keep playing until user hits ESC or gets 2 targets
//int main() {}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
int main() {

	int ch = _getch();
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
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &snakeBox;
	fixtureDef.density = 1.0f;


	//code for the target
	target.position.Set(0.0f, 4.0f);
	b2Body* targetBod = world.CreateBody(&target);

	//Welcome to the snake game! here are the controls: (...)
	//Press any key to get started! (any key press starts numbers generation)
	while (ch != 'q') {
		update();
		display();

		if (_kbhit() != 0) {
			applyForces();
		}
	}
	//code for the target
}
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
