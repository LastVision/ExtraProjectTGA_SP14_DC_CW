#include "Player.h"

RPG::Player::Player()
{
	mySprite = nullptr;
}

RPG::Player::~Player()
{
	delete mySprite;
	mySprite = nullptr;
}

void RPG::Player::Init(HGE *aHgePointer, std::string aFileName, float aXVelocity, float aYVelocity,
					   float aXPosition, float aYPosition)
{
	SetPosition(aXPosition, aYPosition);
	SetVelocity(aXVelocity, aYVelocity);
	HTEXTURE texture = aHgePointer->Texture_Load(aFileName.c_str());
	mySprite = new hgeSprite(texture, 0, 0, 64, 64);
	aHgePointer->Target_Free(texture);
}

void RPG::Player::Update(float aDeltaTime)
{
	myPosition.myX += myVelocity.myX * aDeltaTime;
	myPosition.myY += myVelocity.myY * aDeltaTime;
}

void RPG::Player::Render()
{
	mySprite->SetZ(1);
	mySprite->Render(myPosition.myX, myPosition.myY);
}

void RPG::Player::SetPosition(const Position &aPosition)
{
	myPosition = aPosition;
}

void RPG::Player::SetPosition(const float aXPosition, const float aYPosition)
{
	myPosition.myX = aXPosition;
	myPosition.myY = aYPosition;
}

const RPG::Position& RPG::Player::GetPosition() const
{
	return myPosition;
}

void RPG::Player::SetVelocity(const Position &aVelocity)
{
	myVelocity = aVelocity;
}

void RPG::Player::SetVelocity(const float aXVelocity, const float aYVelocity)
{
	myVelocity.myX = aXVelocity;
	myVelocity.myY = aYVelocity;
}

const RPG::Position& RPG::Player::SetVelocity() const
{
	return myVelocity;
}