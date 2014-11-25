#pragma once
#include <hge.h>
#include <TimerManager.h>
#include <InputHandler.h>
#include "Player.h"
class Game
{
public:
	Game();
	~Game();

	void Init(HGE *anHge, CU::InputHandler *anInputHandler);
	void Update(float aDeltaTime);
	void Render();

	RPG::Player myPlayer;
private:
	CU::InputHandler *myInput;
};

