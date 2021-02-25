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

//define the gravity vector
b2Vec2 gravity(0.0f, -10.0f); ///lower gravity if necessary

//create the world object
b2World world(gravity);


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
	//if()
}


//moves the target to a new location
//location will be in the range of -5.0 -> 5.0 for both x and y
//make the location random (within the bounds)
void moveTarget(float& xPos, float& yPos) {
	//if()
	
}

int main() {
	//create the ground body and set the position
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, -10.0f);

	//pass the ground 
	b2Body* groundBody = world.CreateBody(&groundBodyDef);
	
}
