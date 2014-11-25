#include "Game.h"

Game::Game()
{
	myHge = nullptr;
	myInput = nullptr;
	myRunningCheck = false;
	myAPlayerWonCheck = false;
}

Game::~Game()
{

}

void Game::Init(HINSTANCE aInstanceHandler)
{
	myHge = hgeCreate(HGE_VERSION);
	myHge->System_SetState(HGE_WINDOWED, true);
	myHge->System_SetState(HGE_USESOUND, false);
	myHge->System_SetState(HGE_SCREENWIDTH, 800);
	myHge->System_SetState(HGE_SCREENHEIGHT, 600);
	myHge->System_SetState(HGE_SCREENBPP, 32);
	myHge->System_SetState(HGE_TITLE, "Pong 2014 TGA Edition Alpha");
	myHge->System_SetState(HGE_SHOWSPLASH, false);

	if (myHge->System_Initiate())
	{
		myTimer.UpdateTimers();
		srand(static_cast<unsigned int>(myTimer.GetDeltaTime()));
		//Game Inits here
		myScore.Init(myHge, static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) / 2));
		myPlayerOne.Init(myHge, "res/paddle.png", 16, 96, 0, 
						 static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) / 2));
		myPlayerTwo.Init(myHge, "res/paddle.png", 16, 96, 
						 static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) - myPlayerTwo.GetSize().myWidth), 
						 static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) / 2));
		myBall.Init(myHge, "res/ball.png", 16, 16,
					static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) / 2),
					static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) / 2), 2, 2);

		myBall.Reset();
		myScore.Reset();
		myInput = new CU::InputHandler(GetActiveWindow(), aInstanceHandler, DISCL_FOREGROUND, DISCL_FOREGROUND);
		myHge->System_Start();
		
	}
	else
	{
		MessageBox(nullptr, myHge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		myRunningCheck = false;
	}
	myRunningCheck = true;
}

void Game::Run()
{
	while (myRunningCheck == true)
	{
		Update();
		Render();
	}
	delete myInput;
	myInput = nullptr;
	myHge->System_Shutdown();
	myHge->Release();
}

void Game::Update()
{
	myInput->Update();
	myTimer.UpdateTimers();
	
	myDelta = static_cast<float>(myTimer.GetDeltaTime() * 0.0001);
	if (myInput->GetKeyIsDown(DIK_ESCAPE) == true)
	{
		myRunningCheck = false;
		return;
	}
	if (myInput->GetKeyIsDown(DIK_RETURN) == true)
	{
		if (myAPlayerWonCheck == true)
		{
			myBall.Reset();
			myScore.Reset();
			myPlayerOne.Reset();
			myPlayerTwo.Reset();
			myAPlayerWonCheck = false;
		}
	}
	if (myAPlayerWonCheck == false)
	{
		if (myInput->GetKeyIsDown(DIK_W) == true)
		{
			myPlayerOne.SetVelocity(0, -5);
		}
		else if (myInput->GetKeyIsDown(DIK_S) == true)
		{
			myPlayerOne.SetVelocity(0, 5);
		}
		else if (myInput->GetKeyIsDown(DIK_A) == true)
		{
			myPlayerOne.SetVelocity(-5, 0);
		}
		else if (myInput->GetKeyIsDown(DIK_D) == true)
		{
			myPlayerOne.SetVelocity(5, 0);
		}
		else
		{
			myPlayerOne.SetVelocity(0, 0);
		}
		if (myInput->GetKeyIsDown(DIK_UPARROW) == true)
		{
			myPlayerTwo.SetVelocity(0, -5);
		}
		else if (myInput->GetKeyIsDown(DIK_DOWNARROW) == true)
		{
			myPlayerTwo.SetVelocity(0, 5);
		}
		else if (myInput->GetKeyIsDown(DIK_LEFTARROW) == true)
		{
			myPlayerTwo.SetVelocity(-5, 0);
		}
		else if (myInput->GetKeyIsDown(DIK_RIGHTARROW) == true)
		{
			myPlayerTwo.SetVelocity(5, 0);
		}
		else
		{
			myPlayerTwo.SetVelocity(0, 0);
		}
		//Game updates here
		myPlayerOne.Update(myDelta);
		myPlayerTwo.Update(myDelta);
		myBall.Collision(myPlayerOne);
		myBall.Collision(myPlayerTwo);
		myBall.Update(myDelta);

		if (myBall.GetIsOutside() == Pong::eOutsideArea::LEFT)
		{
			//Score to player one;
			myScore.AddScore(static_cast<int>(Pong::eOutsideArea::RIGHT));
			myBall.Reset();
		}
		else if (myBall.GetIsOutside() == Pong::eOutsideArea::RIGHT)
		{
			//Score to player two;
			myScore.AddScore(static_cast<int>(Pong::eOutsideArea::LEFT));
			myBall.Reset();
		}
		if ((myScore.GetScore(static_cast<int>(Pong::eOutsideArea::LEFT)) >= 3) ||
			(myScore.GetScore(static_cast<int>(Pong::eOutsideArea::RIGHT)) >= 3))
		{
			myAPlayerWonCheck = true;
		}
	}

	myInput->CapturePreviousInput();
}

void Game::Render()
{
	myHge->Gfx_BeginScene();
	myHge->Gfx_Clear(0);

	// Game Render here
	myScore.Render();
	myPlayerOne.Render();
	myPlayerTwo.Render();
	myBall.Render();
	
	myHge->Gfx_EndScene();
}

int WINAPI WinMain(HINSTANCE aInstanceHandler, HINSTANCE, LPSTR, int)
{
	
	Game game;
	game.Init(aInstanceHandler);
	game.Run();
	return 0;
}