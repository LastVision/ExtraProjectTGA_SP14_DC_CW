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
	anHge->System_GetState(HGE_SCREENHEIGHT);
	myPlayer.Init(anHge, "res/textures/hero.png", 0.0f, 0.0f, 100.0f, 100.0f);
}

void Game::Update(float aDeltaTime)
{
	int a = static_cast<int>(aDeltaTime);
	int b = 0;
	a += b;
	myPlayer.Update(aDeltaTime);
}

void Game::Render()
{
	myPlayer.Render();
}