#pragma once
void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);

//part 2
void processInput();
void ApplyForceUp(b2Body* player);
void ApplyForceDown(b2Body* player);
void ApplyForceLeft(b2Body* player);
void ApplyForceRight(b2Body* player);
void StopMoving(b2Body* player);
void ReverseGravity(b2Body* body);
void setUpTargets(int cnt);
bool selectNextTarget(); //check if this needs to be here or if it can
//be exclusive to one cpp

//create the world object
extern b2World world;
extern b2Body* body;

////Part 2 global variables (use extern, define in snake.cpp
//extern b2Vec2 TargetLocations[];
//extern b2Vec2 currentLocation;