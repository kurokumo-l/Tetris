#include "Game.h"

bool Game::isRunning = false;

void Game::Init()
{
	isRunning = true;
}

void Game::Quit()
{
	isRunning = false;
}

void Game::Rotate()
{
}
void Game::MoveDown()
{
}
void Game::MoveLeft()
{
}
void Game::MoveRight()
{
}