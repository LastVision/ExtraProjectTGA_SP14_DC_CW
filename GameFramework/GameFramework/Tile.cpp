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

void RPG::Tile::Init(HGE *aHgePointer, std::string aFileName, float aXPosition, float aYPosition)
{
	SetPosition(aXPosition, aYPosition);
	HTEXTURE texture = aHgePointer->Texture_Load(aFileName.c_str());
	mySprite = new hgeSprite(texture, 0, 0, 16, 16);
	aHgePointer->Target_Free(texture);
}

void RPG::Tile::Update(float aDeltaTime)
{
	float a = aDeltaTime;
	a = a *a;
}

void RPG::Tile::Render()
{
	mySprite->SetZ(0);
	mySprite->Render(myPosition.myX, myPosition.myY);
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