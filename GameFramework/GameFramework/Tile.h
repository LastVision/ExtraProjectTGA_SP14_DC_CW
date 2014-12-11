#pragma once
#include <hgesprite.h>
#include <tinyxml2.h>
#include <string>
#include "Player.h"
namespace RPG
{
	struct TileTexture
	{
		float myRow;
		float myCol;
		float mySize;
		int myId;
		std::string myFile;
	};
	class Tile
	{
	public:
		Tile();
		~Tile();

		void Init(HGE *aHgePointer, std::string aFileName, float aXPosition, float aYPosition, float aXScale, float aYScale, float aImgRow, float aImgCol, float aImgSize);
		void LoadAndInit(HGE *aHgePointer, tinyxml2::XMLElement *aNode);
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