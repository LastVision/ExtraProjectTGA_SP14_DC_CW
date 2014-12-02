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
	myGrassTiles.reserve((anHge->System_GetState(HGE_SCREENWIDTH) * anHge->System_GetState(HGE_SCREENHEIGHT))/16);
	myInput = anInputHandler;
	myPlayer.Init(anHge, "res/textures/hero.png", 0.0f, 0.0f, 
				  static_cast<float>(anHge->System_GetState(HGE_SCREENWIDTH) / 2) - 64,
				  static_cast<float>(anHge->System_GetState(HGE_SCREENHEIGHT) / 2) - 64);
	myGrassTile.Init(anHge, "res/textures/spritesheet.png", 10, 10);
	
	for (int i = 0; i < 100; ++i)
	{
		myGrassTiles.push_back(&myGrassTile);
	}
	float x = 0;
	float y = 0;
	for (unsigned int i = 0; i < myGrassTiles.size(); ++i)
	{
		myGrassTiles.at(i)->SetPosition(x * 16, y * 16);
		++x;
		if (x >= anHge->System_GetState(HGE_SCREENWIDTH) / 16)
		{
			x = 0;
			++y;
		}
	}
}

bool Game::Update(float aDeltaTime)
{
	if (myInput->GetKeyIsDown(DIK_ESCAPE) == true)
	{
		return true;
	}
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
	return false;
}

void Game::Render()
{
	myGrassTile.Render();
	for (unsigned int i = 0; i < myGrassTiles.size(); ++i)
	{
		myGrassTiles.at(i)->Render();
	}
	myPlayer.Render();
	
}