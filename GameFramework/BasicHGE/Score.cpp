#include "Score.h"

Pong::Score::Score()
{
	myPlayerOneScore = 0;
	myPlayerTwoScore = 0;
	myFont = nullptr;
	myHge = nullptr;
}

Pong::Score::~Score()
{
	
}

void Pong::Score::Init(HGE *aHge, float aXPosition, float aYPosition)
{
	myPlayerOneScore = 0;
	myPlayerTwoScore = 0;
	SetPosition(aXPosition, aYPosition);
	myHge = aHge;
	myFont = new hgeFont("font.fnt");
}

void Pong::Score::Reset()
{
	myPlayerOneScore = 0;
	myPlayerTwoScore = 0;
}

void Pong::Score::Render()
{
	std::stringstream ss;
	if (myPlayerOneScore >= 3 || myPlayerTwoScore >= 3)
	{
		if (myPlayerOneScore >= 3)
		{
			ss << "Player One Is A Winner!";
		}
		else
		{
			ss << "Player Two Is A Winner!";
		}
		myFont->SetScale(0.4f);
		myFont->printf(static_cast<float>(myHge->System_GetState(HGE_SCREENWIDTH) / 2),
					   static_cast<float>(myHge->System_GetState(HGE_SCREENHEIGHT) / 2),
					   HGETEXT_CENTER, ss.str().c_str());
	}
	else
	{
		ss << std::to_string(myPlayerOneScore) << " - " << std::to_string(myPlayerTwoScore);
		myFont->SetScale(1.0f);
		myFont->printf(myPosition.myX, myPosition.myY, HGETEXT_CENTER, ss.str().c_str());
	}
	
}

void Pong::Score::AddScore(const int aPlayerSide)
{
	if (aPlayerSide == static_cast<int>(eOutsideArea::LEFT))
	{
		myPlayerOneScore++;
	}
	if (aPlayerSide == static_cast<int>(eOutsideArea::RIGHT))
	{
		myPlayerTwoScore++;
	}
}

const int Pong::Score::GetScore(const int aPlayerSide) const
{
	if (aPlayerSide == static_cast<int>(eOutsideArea::LEFT))
	{
		return myPlayerOneScore;
	}
	else if (aPlayerSide == static_cast<int>(eOutsideArea::RIGHT))
	{
		return myPlayerTwoScore;
	}
	else
	{
		return 0;
	}
}

void Pong::Score::SetPosition(const Position &aPosition)
{
	myPosition = aPosition;
}

void Pong::Score::SetPosition(const float aXPosition, const float aYPosition)
{
	myPosition.myX = aXPosition;
	myPosition.myY = aYPosition;
}

const Pong::Position& Pong::Score::GetPosition() const
{
	return myPosition;
}