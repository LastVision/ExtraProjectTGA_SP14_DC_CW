#pragma once
#include <hge.h>
#include <TimerManager.h>
#include <InputHandler.h>
#include <vector>
#include "Player.h"
#include "Tile.h"
class Game
{
public:
	Game();
	~Game();

	void Init(HGE *anHge, CU::InputHandler *anInputHandler);
	bool Update(float aDeltaTime);
	void Render();
private:
	CU::InputHandler *myInput;
	RPG::Player myPlayer;
	RPG::Tile myGrassTile;
	std::vector<RPG::Tile*> myGrassTiles;
};

