#include <iostream>
using namespace std;

#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
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
//extern b2Body snake;
//x and y positions
float xVal;
float yVal;
int ch;

int countUp = 0;
//define the gravity vector
b2Vec2 gravity(0.0f, -.1f); ///lower gravity if necessary

//create the world object
b2World world(gravity);

//the body definition for each item
b2Body* body;

//PART 2 GLOBAL VARIABLES

//stores multiple b2Vec2 for each position of the target for the game
b2Vec2 TargetLocations[11];

//variable to be used to store multiple b2Vec2 for each position of
//the target for the game
b2Vec2* currentLocation;

//create a typedef for the function pointers
typedef;
typedef void (*inputFunction)(b2Body*);
typedef void(*inputFuntion)(b2World*);
inputFunction myFun;
//tracker to see if gravity is reversed already or not
bool revGrav = false;
//PART 2 CODE STARTS HERE

//applyforces functions will be used here (processInput checks which input goes to 
//which applyforces. 
//at the end of each call, call back to processInput to make sure
//program can keep checking.
void processInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		myFun = ApplyForceUp;
		//processInput();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		myFun = ApplyForceLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		myFun = ApplyForceDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		myFun = ApplyForceRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		myFun = StopMoving;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		myFun = ReverseGravity;
	}
	if (myFun != nullptr) {
		myFun(body);
	}

	//myFun(world);
}

//Applies forces in the four main directions of UP DOWN LEFT RIGHT
void ApplyForceUp(b2Body* player) {
	player->ApplyForceToCenter(b2Vec2(0.0f, 100.0f), true);
}
void ApplyForceDown(b2Body* player) {
	player->ApplyForceToCenter(b2Vec2(0.0f, -100.0f), true);
}
void ApplyForceLeft(b2Body* player) {
	player->ApplyForceToCenter(b2Vec2(-100.0f, 0.0f), true);
}
void ApplyForceRight(b2Body* player) {
	player->ApplyForceToCenter(b2Vec2(100.0f, 0.0f), true);
}
//tells the snake object to stop moving by setting the 
//b2Body velocity to 0
void StopMoving(b2Body* player) {
	player->SetLinearVelocity(b2Vec2(0.0f,0.0f));
	
}

//reverses gravity by calling the world method
//Checks with a bool to see if gravity is already reversed or not.
void ReverseGravity(b2Body* body) {
	//*world = &world;
	if (revGrav == false) {
		world.SetGravity(b2Vec2(0.0f, .1f));
		revGrav = true;
	}
	else {
		world.SetGravity(b2Vec2(0.0f, -.1f));
		revGrav = false;
	}
}

void setupTargets(int cnt) {
	//prompts the user for the number of targets to use in the
	//game from 1 to 10+ (error check the values) 
	//creates an array of b2Vec2 positions for the target to move to(sets the global variable
	//add one additional one at the end of the array with the position of
	//-1000,-1000 to use to stop the game. 
	//when the target is moved to that end one(-1k,-1k) then you are done.
	if (cnt < 1) {
		cnt = 1;//this prevents the user from entering a number too low
	}
	if (cnt > 10) {
		cnt = 10; //this prevents the number from being anything too large to work with
	}
	for (int i = 0; i < cnt; i++) {
		TargetLocations[i] = b2Vec2(-10, 0);
	}
	TargetLocations[cnt++] = b2Vec2(-1000, -1000);

}

//
bool selectNextTarget() {
//	//moves the currentTarget pointer to the next valid target
//	//returns true if there are more targets
//	//return false if there are no more targets
	
	/*currentLocation = &TargetLocations[countUp++];*/
	if (TargetLocations[countUp++] != b2Vec2(-1000,-1000)) {
		currentLocation = &TargetLocations[countUp++];
		return true;
	}
	else {
		currentLocation = &TargetLocations[countUp++];
		return false;
	}
	countUp++;
}
//PART 1 CODE STARTS HERE


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
	printf("Snake: %4.2f , %4.2f Target: %4.2f, %4.2f\n", position.x, position.y ,xVal, yVal);
}

//reads the key presses and applies the forces to the player to move
//use ApplyForceToCenter to add the force to the snake
//will NOT be moving the player directly
void applyForces() {
	//bind to wasd for direction
	ch = _getch();
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
	//take the value and push it into a recognized variable
	xVal = xPos;
	yVal = yPos;
}


