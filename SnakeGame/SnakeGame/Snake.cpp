#include <iostream>
using namespace std;

//add the header to the file
#include "snake.h"
#include <Box2D.h>
//define all global variables here:
//things will go fast (possibly)
float timeStep = 1.0f / 60.0f; //change to 1 / 1000 if moving too fast
int velocityIterations = 6; //int32 threw error.
int positionIterations = 2;
b2Vec2 gravity(0.0f, -10.0f); ///lower gravity if necessary
b2World world(gravity);
//updates the physics world, this will not direcly be
//moving the snake, just updating the Box2D world.
void update() {
	 //referencing above, is this step necessary or could it be done just above?
	world.Step(timeStep, velocityIterations, positionIterations);
}

//displays the position of the target and the player
void display() {

}


//reads the key presses and applies the forces to the player to move
//use ApplyForceToCenter to add the force to the snake
//will NOT be moving the player directly
void applyForces() {

}


//moves the target to a new location
//location will be in the range of -5.0 -> 5.0 for both x and y
//make the location random (within the bounds)
void moveTarget(float& xPos, float& yPos) {

}

//introduce the game to the user with instructions for the keys
//creates physics world(b2world) and snake(physics body b2body)
//creates a loop to keep playing until user hits ESC or gets 2 targets
int main() {
	
}