#include "Game.h"
#include "Tetromio.h"

bool Game::isRunning = false;

int Game::currentRow = 1;
int Game::currentCol = 1;

Game::Tetromino Game::currentTetromino;

void Game::Init()
{
	isRunning = true;
    currentTetromino = Game::I;
}

void Game::Quit()
{
	isRunning = false;
}

void Game::Rotate()
{
	currentTetromino = RotateTetromino(currentTetromino);
}
void Game::MoveDown()
{
	currentRow++;
}
void Game::MoveLeft()
{
	currentCol--;
}
void Game::MoveRight()
{
	currentCol++;
}