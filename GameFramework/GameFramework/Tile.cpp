#include "Tile.h"

RPG::Tile::Tile()
{
	mySprite = nullptr;
}

RPG::Tile::~Tile()
{
	delete mySprite;
	mySprite = nullptr;
}

void RPG::Tile::Init(HGE *aHgePointer, std::string aFileName, float aXPosition, float aYPosition, float aXScale, float aYScale)
{
	SetPosition(aXPosition, aYPosition);
	SetScale(aXScale, aYScale);
	mySprite = new hgeSprite(aHgePointer->Texture_Load(aFileName.c_str()), 0, 0, 16, 16);
}

void RPG::Tile::Update(float aDeltaTime)
{
	float a = aDeltaTime;
	a = a *a;
}

void RPG::Tile::Render()
{
	mySprite->RenderEx(myPosition.myX, myPosition.myY, 0, myScale.myY, myScale.myX);
}

void RPG::Tile::SetPosition(const Position &aPosition)
{
	myPosition = aPosition;
}

void RPG::Tile::SetPosition(const float aXPosition, const float aYPosition)
{
	myPosition.myX = aXPosition;
	myPosition.myY = aYPosition;
}

const RPG::Position& RPG::Tile::GetPosition() const
{
	return myPosition;
}

void RPG::Tile::SetScale(const Position &aScale)
{
	myScale = aScale;
}

void RPG::Tile::SetScale(const float aXScale, const float aYScale)
{
	myScale.myX = aXScale;
	myScale.myY = aYScale;
}

const RPG::Position& RPG::Tile::GetScale() const
{
	return myScale;
}