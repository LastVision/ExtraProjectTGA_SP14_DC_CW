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

	void Init(HINSTANCE, bool aRunningCheck);
	bool Run();
	void Update();
	void Render();
	void Shutdown();
private:
	HGE *myHge;
	CU::InputHandler *myInput;
	CU::TimerManager myTimer;

	Game myGame;

	float myDelta;
	bool myRunningCheck;
};