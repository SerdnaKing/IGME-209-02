#include <iostream>
using namespace std;

//add the header to the file
#include <Box2D.h>
#include "snake.h"

#include <conio.h> //for kbhit and _getch
#include <random> //for random target location generation
//define all global variables here:
//things will go fast (possibly)
float timeStep = 1.0f / 1000.0f; //change to 1 / 1000 if moving too fast
int velocityIterations = 6; //int32 threw error.
int positionIterations = 2;

//int ch; //the character to be read by getch

//x and y positions
float xVal;
float yVal;
//int yVal;
//define the gravity vector
b2Vec2 gravity(0.0f, -.1f); ///lower gravity if necessary

//create the world object
b2World world(gravity);

//create the target box
//b2BodyDef target;

//b2Body* body2;
//the body definition for each item
b2Body* body;

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
	b2Vec2 position = body->GetPosition();
	//b2Vec2 targetLoc = body2->GetPosition();
	printf("Snake: %4.2f , %4.2f Target: %4.2f, %4.2f\n", position.x, position.y ,xVal, yVal);
}


//reads the key presses and applies the forces to the player to move
//use ApplyForceToCenter to add the force to the snake
//will NOT be moving the player directly
void applyForces() {
	//bind to wasd for direction
		int ch = _getch();
		if (ch == 'w') {

			body->ApplyForceToCenter(b2Vec2(0,100), true);
		}
		if (ch == 'a') {
			body->ApplyForceToCenter(b2Vec2(-100, 0), true);
		}
		if (ch == 's') {
			body->ApplyForceToCenter(b2Vec2(0, -100), true);
		}
		if (ch == 'd') {
			body->ApplyForceToCenter(b2Vec2(100, 0), true);
		}
		
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
	//target.position.Set(xVal, yVal);
	
}
