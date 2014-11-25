#pragma once
#include "Ball.h"
#include <hgefont.h>
#include <sstream>
namespace Pong
{
	class Score
	{
	public:
		Score();
		~Score();

		void Init(HGE *aHge, float aXPosition = 0, float aYPosition = 0);
		void Reset();
		void Render();

		void AddScore(const int aPlayerSide);
		const int GetScore(const int aPlayerSide) const;

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;
	private:
		int myPlayerOneScore;
		int myPlayerTwoScore;
		Position myPosition;
		hgeFont *myFont;
		HGE *myHge;
	};
}