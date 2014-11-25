#pragma once
#include <hge.h>
#include <InputHandler.h>
#include <TimerManager.h>
#include "Game.h"
class Window
{
public:
	Window();
	~Window();

	void Init(HINSTANCE);
	void Run();
	void Update();
	void Render();
private:
	HGE *myHge;
	CU::InputHandler *myInput;
	CU::TimerManager myTimer;

	Game myGame;

	float myDelta;
	bool myRunningCheck;
};