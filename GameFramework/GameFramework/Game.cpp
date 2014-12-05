#include "Game.h"

Game::Game()
{
	myInput = nullptr;
	myPlayers.Init(1, true);
	myTiles.Init(0, true);
	myDoc.LoadFile("data/GameData.xml");
}

Game::~Game()
{
	delete myInput;
	myInput = nullptr;
}

void Game::Init(HGE *anHge, CU::InputHandler *anInputHandler)
{
	myInput = anInputHandler;
	tinyxml2::XMLElement *rootElement = myDoc.FirstChildElement("root");
	tinyxml2::XMLElement *gameElement = rootElement->FirstChildElement("game");
	tinyxml2::XMLElement *levelElement = gameElement->FirstChildElement("level");
	std::string level = levelElement->Attribute("name");
	if (level == "tutorial")
	{
		tinyxml2::XMLElement *map = levelElement->FirstChildElement("map");
		myTiles.ReInit(static_cast<unsigned short>(map->IntAttribute("width") * map->IntAttribute("height")), true);
		unsigned short initTimes = 0;
		tinyxml2::XMLElement *tiles = map->FirstChildElement("tiles");
		for (tinyxml2::XMLElement *e = tiles->FirstChildElement("tile"); e != nullptr; e = e->NextSiblingElement("tile"))
		{
			myTiles.Add(RPG::Tile());
			myTiles[initTimes].Init(anHge, e->FirstChildElement("gfx")->Attribute("file"),
									e->FirstChildElement("position")->FloatAttribute("x") * (16 + e->FirstChildElement("scale")->FloatAttribute("x")),
									e->FirstChildElement("position")->FloatAttribute("y") * (16 + e->FirstChildElement("scale")->FloatAttribute("y")),
									e->FirstChildElement("scale")->FloatAttribute("x"),
									e->FirstChildElement("scale")->FloatAttribute("y"));
			++initTimes;
		}
		initTimes = 0;
		for (tinyxml2::XMLElement *e = levelElement->FirstChildElement("player"); e != nullptr; e = e->NextSiblingElement("player"))
		{
			myPlayers.Add(RPG::Player());
			myPlayers[initTimes].Init(anHge, e->FirstChildElement("gfx")->Attribute("file"), 0, 0,
									  e->FirstChildElement("position")->FloatAttribute("x") * 16,
									  e->FirstChildElement("position")->FloatAttribute("y") * 16);
			++initTimes;
		}
	}
}

bool Game::Update(float aDeltaTime)
{
	if (myInput->GetKeyIsDown(DIK_ESCAPE) == true)
	{
		return true;
	}
	for (int i = 0; i < myPlayers.Size(); ++i)
	{
		if (myInput->GetKeyIsDown(DIK_W) == true)
		{
			myPlayers[i].SetVelocity(0, -2);
		}
		else if (myInput->GetKeyIsDown(DIK_A) == true)
		{
			myPlayers[i].SetVelocity(-2, 0);
		}
		else if (myInput->GetKeyIsDown(DIK_S) == true)
		{
			myPlayers[i].SetVelocity(0, 2);
		}
		else if (myInput->GetKeyIsDown(DIK_D) == true)
		{
			myPlayers[i].SetVelocity(2, 0);
		}
		else
		{
			myPlayers[i].SetVelocity(0, 0);
		}
		myPlayers[i].Update(aDeltaTime);
	}
	return false;
}

void Game::Render()
{
	for (int i = 0; i < myTiles.Size(); ++i)
	{
		myTiles[i].Render();
	}
	for (int i = 0; i < myPlayers.Size(); ++i)
	{
		myPlayers[i].Render();
	}
}