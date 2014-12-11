#include "Tile.h"
#include "Utilities.h"

RPG::Tile::Tile()
{
	mySprite = nullptr;
}

RPG::Tile::~Tile()
{
	delete mySprite;
	mySprite = nullptr;
}

void RPG::Tile::Init(HGE *aHgePointer, std::string aFileName, float aXPosition, float aYPosition, float aXScale, float aYScale, float aImgRow, float aImgCol, float aImgSize)
{
	SetPosition(aXPosition, aYPosition);
	SetScale(aXScale, aYScale);
	mySprite = new hgeSprite(aHgePointer->Texture_Load(aFileName.c_str()), aImgCol * aImgSize, aImgRow *aImgSize, aImgSize, aImgSize);
}

void RPG::Tile::LoadAndInit(HGE *aHgePointer, tinyxml2::XMLElement *aNode)
{
	float row = 0;
	float col = 0;
	float size = 0;
	TINY_CHECKQUERY(aNode->QueryFloatAttribute("row", &row));
	TINY_CHECKQUERY(aNode->QueryFloatAttribute("col", &col));
	TINY_CHECKQUERY(aNode->QueryFloatAttribute("size", &size));
	mySprite = new hgeSprite(aHgePointer->Texture_Load(aNode->Attribute("file")), row * size, col * size, size, size);

	TINY_CHECKQUERY(aNode->QueryFloatAttribute("xPos", &myPosition.myX));
	TINY_CHECKQUERY(aNode->QueryFloatAttribute("yPos", &size));

	TINY_CHECKQUERY(aNode->QueryFloatAttribute("xScale", &size));
	TINY_CHECKQUERY(aNode->QueryFloatAttribute("yScale", &size));
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