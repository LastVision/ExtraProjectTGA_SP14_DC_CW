#include "Player.h"

Pong::Player::Player()
{
	myHge = nullptr;
	mySprite = nullptr;
}

Pong::Player::~Player()
{
	delete mySprite;
	mySprite = nullptr;
	delete myHge;
	myHge = nullptr;
}

void Pong::Player::Init(HGE *aHge, std::string aFileName, float aWidht, float aHeight, float aXPos, float aYPos)
{
	myHge = aHge;
	SetPosition(aXPos, aYPos);
	SetOrginPosition(myPosition);
	SetSize(aWidht, aHeight);
	myTexture = myHge->Texture_Load(aFileName.c_str());
	mySprite = new hgeSprite(myTexture, 0, 0, mySize.myWidth, mySize.myHeight);
	mySprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	myHge->Target_Free(myTexture);
}

void Pong::Player::Reset()
{
	SetPosition(this->myOrginPosition);
}

void Pong::Player::Update(float aDeltaTime)
{
	myPosition.myX += myVelocity.myX * aDeltaTime;
	myPosition.myY += myVelocity.myY * aDeltaTime;
	if (myPosition.myY > (myHge->System_GetState(HGE_SCREENHEIGHT) - mySize.myHeight))
	{
		myPosition.myY = static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) - mySize.myHeight);
	}
	if (myPosition.myY < 0)
	{
		myPosition.myY = 0.0f;
	}
	if (myPosition.myX > (myHge->System_GetState(HGE_SCREENWIDTH) - mySize.myWidth))
	{
		myPosition.myX = static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) - mySize.myWidth);
	}
	if (myPosition.myX < 0)
	{
		myPosition.myX = 0.0f;
	}
}

void Pong::Player::Render()
{
	mySprite->Render(myPosition.myX, myPosition.myY);
}

void Pong::Player::SetSprite(hgeSprite *aSprite)
{
	mySprite = aSprite;
}

const hgeSprite& Pong::Player::GetSprite() const
{
	return *mySprite;
}

void Pong::Player::SetPosition(const Position &aPosition)
{
	myPosition = aPosition;
}

void Pong::Player::SetPosition(const float aXPosition, const float aYPosition)
{
	myPosition.myX = aXPosition;
	myPosition.myY = aYPosition;
}

const Pong::Position& Pong::Player::GetPosition() const
{
	return myPosition;
}

void Pong::Player::SetOrginPosition(const Position &aPosition)
{
	myOrginPosition = aPosition;
}

void Pong::Player::SetOrginPosition(const float aXPosition, const float aYPosition)
{
	myOrginPosition.myX = aXPosition;
	myOrginPosition.myY = aYPosition;
}

const Pong::Position& Pong::Player::GetOrginPosition() const
{
	return myOrginPosition;
}

void Pong::Player::SetVelocity(const Position &aVelocity)
{
	myVelocity = aVelocity;
}

void Pong::Player::SetVelocity(const float aXVelocity, const float aYVelocity)
{
	myVelocity.myX = aXVelocity;
	myVelocity.myY = aYVelocity;
}

const Pong::Position& Pong::Player::GetVelocity() const
{
	return myVelocity;
}


void Pong::Player::SetSize(const Size &aSize)
{
	mySize = aSize;
}

void Pong::Player::SetSize(const float aWidth, const float aHeight)
{
	mySize.myWidth = aWidth;
	mySize.myHeight = aHeight;
}

const Pong::Size& Pong::Player::GetSize() const
{
	return mySize;
}