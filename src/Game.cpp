#include "Game.h"

bool Game::IsRunning = false;

void Game::Init()
{
    IsRunning = true;
}

void Game::Quit()
{
    IsRunning = false;
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