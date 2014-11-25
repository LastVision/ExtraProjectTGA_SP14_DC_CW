#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <InputHandler.h>
#include <TimerManager.h>
#include "Player.h"
#include "Ball.h"
#include "Score.h"
class Game
{
public:
	Game();
	~Game();

	void Init(HINSTANCE);
	void Run();
	void Update();
	void Render();
private:
	HGE *myHge;
	CU::InputHandler *myInput;
	CU::TimerManager myTimer;
	Pong::Player myPlayerOne;
	Pong::Player myPlayerTwo;
	Pong::Ball myBall;
	Pong::Score myScore;

	float myDelta;
	bool myRunningCheck;
	bool myAPlayerWonCheck;
};