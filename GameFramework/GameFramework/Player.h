#pragma once
#include <hgesprite.h>
#include <string>
namespace RPG
{
	struct Position
	{
		float myX;
		float myY;
	};
	class Player
	{
	public:
		Player();
		~Player();

		void Init(HGE *aHgePointer, std::string aFileName, float aXVelocity = 0.0f, float aYVelocity = 0.0f, float aXPosition = 100.0f, float aYPosition = 100.0f);
		void Update(float aDeltaTime);
		void Render();

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;

		void SetVelocity(const Position &aVelocity);
		void SetVelocity(const float aXVelocity, const float aYVelocity);
		const Position& SetVelocity() const;
	private:
		hgeSprite *mySprite;
		Position myPosition;
		Position myVelocity;
	};
}