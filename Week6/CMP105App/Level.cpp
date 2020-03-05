#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	//Initialise game objects
	artOfBall.loadFromFile("gfx/Beach_Ball.png");

	Bawl.setTexture(&artOfBall);
	Bawl.setSize(sf::Vector2f(93, 93));
	Bawl.setOrigin(46.5, 46.5);
	Bawl.setPosition(600, 10);
	Bawl.setInput(input);
	Bawl.receiveWin(window);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	Bawl.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	Bawl.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Bawl);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}