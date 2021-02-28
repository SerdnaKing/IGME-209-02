// SnakeGame.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <Box2D.h>
#include "snake.h";
#include <conio.h>;
extern float xVal; //xLoc in the range of -5 to 5
extern float yVal; //yLoc in the range of -5 to 5
int count; //checks to see if target was hit twice.
bool collide = false;
//introduce the game to the user with instructions for the keys
//creates physics world(b2world) and snake(physics body b2body)
//creates a loop to keep playing until user hits ESC or gets 2 targets

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
	b2FixtureDef snakeFixture;
	snakeFixture.shape = &snakeBox;
	snakeFixture.density = 1.0f;

	//Welcome to the snake game! here are the controls: (...)
	//Press any key to get started! (any key press starts numbers generation)
	


		while (count != 2) {
			//moveTarget(xLoc, yLoc);
			if (count >= 2) {
				break; //this will break the loop effectively
			}
			update();
			display();
			//xLoc = 6.0f;
			//yLoc = rand() - 5 + 5;

		//	xLoc = rand() % -5 + 5; //xLoc in the range of -5 to 5
			//yLoc = rand() % -5 + 5; //yLoc in the range of -5 to 5
			if (_kbhit() != 0) {
				applyForces();

			}
			if (fabs((double)body->GetPosition().x - xVal) <= .5 && fabs((double)body->GetPosition().y - yVal) <= .5 && collide == false) {
				collide = true;
				count++;
				xVal = rand()% 10 - 5;
				yVal = rand()% 10 - 5;
				moveTarget(xVal, yVal);
				 collide = false;
				//display();

			}
			if (ch == 'q') {
				break;
			}
		}
	
}
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
