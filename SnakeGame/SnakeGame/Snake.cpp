#include <iostream>
using namespace std;

//add the header to the file
#include "snake.h"
#include <Box2D.h>
#include <conio.h>
//define all global variables here:
//things will go fast (possibly)
float timeStep = 1.0f / 60.0f; //change to 1 / 1000 if moving too fast
int velocityIterations = 6; //int32 threw error.
int positionIterations = 2;

int ch; //the character to be read by getch

//x and y positions
int xVal;
int yVal;
//define the gravity vector
b2Vec2 gravity(0.0f, -10.0f); ///lower gravity if necessary

//create the world object
b2World world(gravity);

//create the target box
b2BodyDef target;

//create the snake (snake will only be changed in main)


//groundBodyDef.position.Set(0.0f, -10.0f);
//updates the physics world, this will not direcly be
//moving the snake, just updating the Box2D world.
void update() { //this method should be done
	 //referencing above, is this step necessary or could it be done just above?
	world.Step(timeStep, velocityIterations, positionIterations);

	
}

//displays the position of the target and the player
//
void display() {
	
}


//reads the key presses and applies the forces to the player to move
//use ApplyForceToCenter to add the force to the snake
//will NOT be moving the player directly
void applyForces() {
	//bind to wasd for direction
	//if (kbhit != 0) {
		ch = _getch();
		if (ch == 'w') {
			//void b2Body::ApplyForceToCenter(
			//void:: b2Body::ApplyForceToCenter()
		}
		if (ch == 'a') {

		}
		if (ch == 's') {

		}
		if (ch == 'd') {

		}
	//}
}


//moves the target to a new location
//location will be in the range of -5.0 -> 5.0 for both x and y
//make the location random (within the bounds)
void moveTarget(float& xPos, float& yPos) {
	//if()
	//target.
	//take the value and push it into a recognized variable
	xVal = xPos;
	yVal = yPos;
	
	//target.position()
	target.position.Set(xVal, yVal);
	
}

int main() {

	ch = _getch();
	//introduce the user and tell user about the key presses
	//create the ground body and set the position
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	//code for snake (does it need to be here or should there be 
	b2BodyDef snake;
	snake.type = b2_dynamicBody;
	snake.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&snake);

	//code for the target
	target.position.Set(0.0f, 4.0f);
	b2Body* body = world.CreateBody(&target);
	while (ch != 'ESC') {

	}
	//code for the target
}
