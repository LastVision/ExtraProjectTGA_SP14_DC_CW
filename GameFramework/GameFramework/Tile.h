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

		void Init(HGE *aHgePointer, std::string aFileName, float aXPosition, float aYPosition, float aXScale, float aYScale, float aImgRow, float aImgCol, float aImgSize);
		void Update(float aDeltaTime);
		void Render();

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;

		void SetScale(const Position &aScale);
		void SetScale(const float aXScale, const float aYScale);
		const Position& GetScale() const;
	private:
		hgeSprite *mySprite;
		Position myPosition;
		Position myScale;
	};
}