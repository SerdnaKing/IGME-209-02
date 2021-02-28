#pragma once
void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);
//b2Vec2 gravity(0.0f, -1.0f); ///lower gravity if necessary

//create the world object
extern b2World world;

//create the target box
extern b2BodyDef target;


extern b2Body* body;
//int main();