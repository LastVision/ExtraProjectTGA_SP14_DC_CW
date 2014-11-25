#include "Game.h"

Game::Game()
{
	myInput = nullptr;
}

Game::~Game()
{

}

void Game::Init(HGE *anHge, CU::InputHandler *anInputHandler)
{
	myInput = anInputHandler;
	myPlayer.Init(anHge, "hero.png", 0.0f, 0.0f, 100.0f, 100.0f);
}

void Game::Update(float aDeltaTime)
{
	myPlayer.Update(aDeltaTime);
}

void Game::Render()
{
	myPlayer.Render();
}