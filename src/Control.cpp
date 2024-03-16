#include "Control.h"
#include "Game.h"
#include "Utils.h"

void Game::HandleInput()
{
    if (Utils::IsKeyDown('Q'))
    {
        Game::Quit();
    }
    if (Utils::IsKeyDown('W'))
    {
        Game::Rotate();
    }
    if (Utils::IsKeyDown('S'))
    {
        Game::MoveDown();
    }
    if (Utils::IsKeyDown('A'))
    {
        Game::MoveLeft();
    }
    if (Utils::IsKeyDown('D'))
    {
        Game::MoveRight();
    }
}