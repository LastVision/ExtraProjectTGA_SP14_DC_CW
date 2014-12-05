#pragma once
#include <hge.h>
#include <TimerManager.h>
#include <InputHandler.h>
#include <GrowingArray.h>
#include <tinyxml2.h>
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
	tinyxml2::XMLDocument myDoc;
	CU::InputHandler *myInput;
	CU::GrowingArray<RPG::Player, int> myPlayers;
	CU::GrowingArray<RPG::Tile, int> myTiles;
};

