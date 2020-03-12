#include "BallDos.h"
#include <stdlib.h>
#include <iostream>

BallDos::BallDos()
{
	speed = 50.f;
	acceleration = 500.f;
}

BallDos::~BallDos()
{

}

void BallDos::update(float dt)
{
	int x1 = input->getMouseX();
	int y1 = input->getMouseY();
	target = sf::Vector2f(x1, y1);

	//Calculate direction and move
	direction = target - getPosition();
	float mag = Vector::magnitude(direction);
	direction = Vector::normalise(direction);
	sf::Vector2f mouseCurr = sf::Vector2f(input->getMouseX(), input->getMouseY());
	
	float sc = 1;
	if (mag < 20) {
		sc = 0.02;
	}
	velocity += (direction * acceleration) * dt * sc  ;
	/*TODO:
	- Move code above into updateVelocoty new function
	- in update velocity, also call another new function to check mouse moveemnt level. 
	
	*/
	//new function check mouse movement amount
	mouseCurr = sf::Vector2f(input->getMouseX(), input->getMouseY());
	if (Vector::magnitude(mouseOld - mouseCurr) > 100) {
		velocity.x = 0;
		velocity.y = 0;
		mouseOld = mouseCurr;
	}
	//Bit ah v = u + at
	setPosition(getPosition() + (velocity*dt));

	//If object is close enough to target...
	if(Vector::magnitude(target - getPosition()) < 10.f) {
		setPosition(target);
	}


	//std::cout << "(" << velocity.x << "),(" << velocity.y << ")";
	//system("CLS");
}

void BallDos::updateVelocity(float dt)
{
}
