#pragma once
void update();

//part 2
void processInput();
void ApplyForceUp(b2Body* player);
void ApplyForceDown(b2Body* player);
void ApplyForceLeft(b2Body* player);
void ApplyForceRight(b2Body* player);
void StopMoving(b2Body* player);
void ReverseGravity(b2Body* body);
void setupTargets(int cnt);
bool selectNextTarget();

//create the world object
extern b2World world;
extern b2Body* body;
