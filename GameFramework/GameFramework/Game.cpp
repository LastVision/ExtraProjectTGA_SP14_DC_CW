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
	anHge->System_GetState(HGE_SCREENHEIGHT);
	myPlayer.Init(anHge, "res/textures/hero.png", 0.0f, 0.0f, 100.0f, 100.0f);
}

void Game::Update(float aDeltaTime)
{
	int a = static_cast<int>(aDeltaTime);
	int b = 0;
	a += b;
	if (myInput->GetKeyIsDown(DIK_W) == true)
	{
		myPlayer.SetVelocity(0, -5);
		OutputDebugStringW(L"W");
	}
	else if (myInput->GetKeyIsDown(DIK_A) == true)
	{
		myPlayer.SetVelocity(-5, 0);
	}
	else if (myInput->GetKeyIsDown(DIK_S) == true)
	{
		myPlayer.SetVelocity(0, 5);
	}
	else if (myInput->GetKeyIsDown(DIK_D) == true)
	{
		myPlayer.SetVelocity(5, 0);
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