#include "Game.h"

Game::Game()
{
	myInput = nullptr;
}

Game::~Game()
{
	delete myInput;
	myInput = nullptr;
}

void Game::Init(HGE *anHge, CU::InputHandler *anInputHandler)
{
	myInput = anInputHandler;
	myPlayer.Init(anHge, "res/textures/hero.png", 0.0f, 0.0f, 
				  static_cast<float>(anHge->System_GetState(HGE_SCREENWIDTH) / 2) - 64,
				  static_cast<float>(anHge->System_GetState(HGE_SCREENHEIGHT) / 2) - 64);
}

void Game::Update(float aDeltaTime)
{
	if (myInput->GetKeyIsDown(DIK_W) == true)
	{
		myPlayer.SetVelocity(0, -2);
	}
	else if (myInput->GetKeyIsDown(DIK_A) == true)
	{
		myPlayer.SetVelocity(-2, 0);
	}
	else if (myInput->GetKeyIsDown(DIK_S) == true)
	{
		myPlayer.SetVelocity(0, 2);
	}
	else if (myInput->GetKeyIsDown(DIK_D) == true)
	{
		myPlayer.SetVelocity(2, 0);
	}
	else
	{
		myPlayer.SetVelocity(0, 0);
	}
	myPlayer.Update(aDeltaTime);
}

void Game::Render()
{
	myPlayer.Render();
}