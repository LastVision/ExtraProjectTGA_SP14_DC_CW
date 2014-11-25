#pragma once
#include <hgesprite.h>
#include <stdlib.h>
#include <string>
#include "Player.h"
namespace Pong
{
	enum class eOutsideArea
	{
		NONE,
		LEFT, 
		RIGHT
	};
	class Ball
	{
	public:
		Ball();
		~Ball();

		void Init(HGE *aHge, std::string aFileName, float aWidth = 16, float aHeight = 16, float aXPos = 0, float aYPos = 0, float aXVel = 0.01f, float aYVel = 0.01f);
		void Reset();
		void Update(float aDeltaTime);
		bool IsCollided(const Position &aPosition, const Size &aSize);
		void Collision(Player &aPlayer);
		void Render();

		void SetSprite(hgeSprite *aSprite);
		const hgeSprite& GetSprite() const;

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;

		void SetVelocity(const Position &aVelocity);
		void SetVelocity(const float aXVelocity, const float aYVelocity);
		const Position& GetVelocity() const;

		void SetSize(const Size &aSize);
		void SetSize(const float aWidth, const float aHeight);
		const Size& GetSize() const;

		const eOutsideArea GetIsOutside() const;
	private:
		hgeSprite *mySprite;
		HTEXTURE myTexture;
		Position myPosition;
		Position myVelocity;
		Size mySize;
		HGE *myHge;
		int myIsOutsideCheck;
	};
}