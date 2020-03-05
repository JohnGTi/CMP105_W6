#pragma once
#include "Framework/GameObject.h"

class Ball : public GameObject
{
private:
	//Attributes:
	float scale;
	bool isJumping;

	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;

	sf::RenderWindow* winDoe;

public:
	//Functions:
	Ball();
	~Ball();

	void receiveWin(sf::RenderWindow* hwnd);

	void handleInput(float dt);
	void update(float dt);
};