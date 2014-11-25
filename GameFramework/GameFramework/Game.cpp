#include "Game.h"

Game::Game()
{
	myHge = nullptr;
	myInput = nullptr;
}

Game::~Game()
{

}

void Game::Init(HGE *anHge, CU::InputHandler *anInputHandler)
{
	myHge = anHge;
	myInput = anInputHandler;
}

void Game::Update(float aDeltaTime)
{
	myDelta = aDeltaTime;
}

void Game::Render()
{

}