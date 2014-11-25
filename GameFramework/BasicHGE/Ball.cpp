#include "Ball.h"

Pong::Ball::Ball()
{
	myHge = nullptr;
	mySprite = nullptr;
	myIsOutsideCheck = 0;
	SetPosition(100, 100);
	SetVelocity(0, 0);
}

Pong::Ball::~Ball()
{
	delete mySprite;
	mySprite = nullptr;
	delete myHge;
	myHge = nullptr;
}

void Pong::Ball::Init(HGE *aHge, std::string aFileName, float aWidth, float aHeight , float aXPos, float aYPos ,float aXVel, float aYVel)
{
	myHge = aHge;
	SetPosition(aXPos, aYPos);
	SetVelocity(aXVel, aYVel);
	SetSize(aWidth, aHeight);
	myTexture = myHge->Texture_Load(aFileName.c_str());
	mySprite = new hgeSprite(myTexture, 0, 0, mySize.myWidth, mySize.myHeight);
	mySprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	myHge->Target_Free(myTexture);
}

void Pong::Ball::Reset()
{
	Position newPosition;
	newPosition.myX = static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) / 2);
	newPosition.myY = static_cast<float>(rand() % myHge->System_GetState(HGE_SCREENHEIGHT));
	SetPosition(newPosition);
	int randomDir = rand()% 8;
	if (randomDir % 4 == 0)
	{
		myVelocity.myX = myVelocity.myX;
		myVelocity.myY = myVelocity.myY;
	}
	else if (randomDir % 4 == 1)
	{
		myVelocity.myX = -myVelocity.myX;
		myVelocity.myY = -myVelocity.myY;
	}
	else if (randomDir % 4 == 2)
	{
		myVelocity.myX = myVelocity.myX;
		myVelocity.myY = -myVelocity.myY;
	}
	else
	{
		myVelocity.myX = -myVelocity.myX;
		myVelocity.myY = myVelocity.myY;
	}
	myIsOutsideCheck = static_cast<int>(eOutsideArea::NONE);
}

void Pong::Ball::Update(float aDeltaTime)
{
	myPosition.myX += myVelocity.myX * aDeltaTime;
	myPosition.myY += myVelocity.myY * aDeltaTime;
}

bool Pong::Ball::IsCollided(const Position &aPosition, const Size &aSize)
{
	if (myPosition.myX > (aPosition.myX + aSize.myWidth))
	{
		return false;
	}
	if ((myPosition.myX + mySize.myWidth) < aPosition.myX)
	{
		return false;
	}
	if (myPosition.myY > (aPosition.myY + aSize.myHeight))
	{
		return false;
	}
	if ((myPosition.myY + mySize.myHeight) < aPosition.myY)
	{
		return false;
	}

	if (aPosition.myX > (myPosition.myX + mySize.myWidth))
	{
		return false;
	}
	if ((aPosition.myX + aSize.myWidth) < myPosition.myX)
	{
		return false;
	}
	if (aPosition.myY > (aPosition.myY + mySize.myHeight))
	{
		return false;
	}
	if ((aPosition.myY + aSize.myHeight) < myPosition.myY)
	{
		return false;
	}
	return true;
}

void Pong::Ball::Collision(Player &aPlayer)
{
	if (myPosition.myY > (myHge->System_GetState(HGE_SCREENHEIGHT) - mySize.myHeight))
	{
		myPosition.myY = static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) - mySize.myHeight);
		myVelocity.myY = -myVelocity.myY;
	}
	if (myPosition.myY < 0)
	{
		myPosition.myY = 0.0f;
		myVelocity.myY = -myVelocity.myY;
	}
	if (myPosition.myX >(myHge->System_GetState(HGE_SCREENWIDTH) - mySize.myWidth))
	{
		myIsOutsideCheck = static_cast<int>(eOutsideArea::RIGHT);
	}
	else if (myPosition.myX < 0)
	{
		myIsOutsideCheck = static_cast<int>(eOutsideArea::LEFT);
	}
	else
	{
		myIsOutsideCheck = static_cast<int>(eOutsideArea::NONE);
	}

	if (IsCollided(aPlayer.GetPosition(), aPlayer.GetSize()) == true)
	{
		myVelocity.myX = -myVelocity.myX;
		//myVelocity.myY = -myVelocity.myY;
	}
}

void Pong::Ball::Render()
{
	mySprite->Render(myPosition.myX, myPosition.myY);
}

void Pong::Ball::SetSprite(hgeSprite *aSprite)
{
	mySprite = aSprite;
}

const hgeSprite& Pong::Ball::GetSprite() const
{
	return *mySprite;
}

void Pong::Ball::SetPosition(const Position &aPosition)
{
	myPosition = aPosition;
}

void Pong::Ball::SetPosition(const float aXPosition, const float aYPosition)
{
	myPosition.myX = aXPosition;
	myPosition.myY = aYPosition;
}

const Pong::Position& Pong::Ball::GetPosition() const
{
	return myPosition;
}

void Pong::Ball::SetVelocity(const Position &aVelocity)
{
	myVelocity = aVelocity;
}

void Pong::Ball::SetVelocity(const float aXVelocity, const float aYVelocity)
{
	myVelocity.myX = aXVelocity;
	myVelocity.myY = aYVelocity;
}

const Pong::Position& Pong::Ball::GetVelocity() const
{
	return myVelocity;
}

void Pong::Ball::SetSize(const Size &aSize)
{
	mySize = aSize;
}

void Pong::Ball::SetSize(const float aWidth, const float aHeight)
{
	mySize.myWidth = aWidth;
	mySize.myHeight = aHeight;
}

const Pong::Size& Pong::Ball::GetSize() const
{
	return mySize;
}

const Pong::eOutsideArea Pong::Ball::GetIsOutside() const
{
	return static_cast<eOutsideArea>(myIsOutsideCheck);
}