#include "Ball.h"

Ball::Ball()
{
	//Initialise gravy value (gravity 9.8, 200 scale, 200 p/s this will need to be uniform).
	scale = 200.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;

	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	//isJumping = false;
}

Ball::~Ball()
{
	
}

void Ball::receiveWin(sf::RenderWindow* hwnd)
{
	winDoe = hwnd;
}

void Ball::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space)) {

		/*if (!isJumping) {
			stepVelocity = jumpVector;
			isJumping = true;
		}*/
		stepVelocity = jumpVector;
	}
}

void Ball::update(float dt)
{
	//Apply gravity force, increasing velocity.
	//Move shape by new velocity.

	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; // ut + (1/2)at^2
	stepVelocity += gravity * dt; // v = u + at  note the += is not =
	setPosition(getPosition() + pos); 
	
	// Check for collision with bottom of window
	if (getPosition().y >= (winDoe->getSize().y - getSize().y/2))
	{
		setPosition(getPosition().x, (winDoe->getSize().y - getSize().y/2));
		stepVelocity = sf::Vector2f(0, 0);
		//isJumping = false;
	}

	if (input->isMouseLDown() == true) {
		setPosition(input->getMouseX(), input->getMouseY());
	}
}
