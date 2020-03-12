#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

/*
author: suP3RsickBoy1999
date created: corona vius eludes time
BallDos is sick it has vibes.
*/

class BallDos : public GameObject
{
private:
	//Attributes:
	float speed;
	float acceleration;

	sf::Vector2f target;
	sf::Vector2f direction;
	sf::Vector2f mouseOld;

public:
	//Functions:
	BallDos();
	~BallDos();

	void update(float dt);
	void updateVelocity(float dt);
};

