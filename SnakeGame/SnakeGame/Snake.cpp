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
float timeStep = 1.0f / 10000.0f; //change to 1 / 1000 if moving too fast
int velocityIterations = 6; //int32 threw error.
int positionIterations = 2;



//int ch; //the character to be read by getch
//extern b2Body snake;
//x and y positions
float xVal;
float yVal;
int ch;
//int scoreCounter = 0;
int countUp = 0;
//define the gravity vector
b2Vec2 gravity(0.0f, -.1f); ///lower gravity if necessary

//create the world object
b2World world(gravity);
int scoreCount = 150;
//the body definition for each item
b2Body* body;

//PART 2 GLOBAL VARIABLES

//stores multiple b2Vec2 for each position of the target for the game
b2Vec2 TargetLocations[11];

//variable to be used to store multiple b2Vec2 for each position of
//the target for the game
b2Vec2* currentLocation;

//create a typedef for the function pointers
//typedef;
typedef void (*inputFunction)(b2Body*);
//typedef void(*inputFuntion)(b2World*);
inputFunction myFun;
//tracker to see if gravity is reversed already or not
bool revGrav = false;
//PART 2 CODE STARTS HERE

//applyforces functions will be used here (processInput checks which input goes to 
//which applyforces. 
//at the end of each call, call back to processInput to make sure
//program can keep checking.
void processInput() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ) {
		scoreCount--;
		myFun = ApplyForceUp;
		//processInput();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		scoreCount--;
		myFun = ApplyForceLeft;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		scoreCount--;
		myFun = ApplyForceDown;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		scoreCount--;
		myFun = ApplyForceRight;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		scoreCount--;
		myFun = StopMoving;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		scoreCount--;
		myFun = ReverseGravity;
	}
	
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
		countUp = 2;
		selectNextTarget();
		
	}*/
	if (myFun != nullptr) {
		myFun(body);
	}
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
	//prompts the user for the number of targets to use in the
	//game from 1 to 10+ (error check the values) 
	//creates an array of b2Vec2 positions for the target to move to(sets the global variable
	//add one additional one at the end of the array with the position of
	//-1000,-1000 to use to stop the game. 
	//when the target is moved to that end one(-1k,-1k) then you are done.
void setupTargets(int cnt) {

	if (cnt < 1) {
		cnt = 1;//this prevents the user from entering a number too low
	}
	if (cnt > 10) {
		cnt = 10; //this prevents the number from being anything too large to work with
	}
	for (int i = 0; i < cnt; i++) {
		xVal = (rand() % 10 - 5);
		yVal = (rand() % 10 - 5);

		TargetLocations[i] = b2Vec2(xVal, yVal);
	}
	TargetLocations[cnt] = b2Vec2(-1000, -1000);
	currentLocation = &TargetLocations[0];
	//countUp = 0;
}

//	//moves the currentTarget pointer to the next valid target
//	//returns true if there are more targets
//	//return false if there are no more targets
bool selectNextTarget() {
	if (*(currentLocation+1) != b2Vec2(-1000,-1000)) {
		currentLocation = &TargetLocations[++countUp];
		return true;
	}
	else {
		return false;
	}
}
//PART 1 CODE STARTS HERE

//groundBodyDef.position.Set(0.0f, -10.0f);
//updates the physics world, this will not direcly be
//moving the snake, just updating the Box2D world.
void update() {
	world.Step(timeStep, velocityIterations, positionIterations);

}




