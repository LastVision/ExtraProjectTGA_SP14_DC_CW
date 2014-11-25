#pragma once
#include <hge.h>
#include <TimerManager.h>
#include <InputHandler.h>
class Game
{
public:
	Game();
	~Game();

	void Init(HGE *anHge, CU::InputHandler *anInputHandler);
	void Update(float aDeltaTime);
	void Render();
private:
	HGE *myHge;
	CU::InputHandler *myInput;
	//CU::TimerManager myTimer;

	float myDelta;
};

