#pragma once
#include <hgesprite.h>
#include <string>
#include "Player.h"
namespace RPG
{
	class Tile
	{
	public:
		Tile();
		~Tile();

		void Init(HGE *aHgePointer, std::string aFileName, float aXPosition = 100.0f, float aYPosition = 100.0f);
		void Update(float aDeltaTime);
		void Render();

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;
	private:
		hgeSprite *mySprite;
		Position myPosition;
	};
}