#pragma once
void update();
void display();
void applyForces();
void moveTarget(float& xPos, float& yPos);

//create the world object
extern b2World world;
extern b2Body* body;