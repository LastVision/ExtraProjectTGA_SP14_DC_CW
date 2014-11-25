#pragma once
#include <hgesprite.h>
#include <string>
namespace Pong
{
	struct Position
	{
		float myX;
		float myY;
	};
	struct Size
	{
		float myWidth;
		float myHeight;
	};
	class Player
	{
	public:
		Player();
		~Player();

		void Init(HGE *aHge, std::string aFileName,float aWidth = 16, float aHeight = 16, float aXPos = 0, float aYPos = 0);
		void Reset();
		void Update(float aDeltaTime);
		void Render();

		void SetSprite(hgeSprite *aSprite);
		const hgeSprite& GetSprite() const;

		void SetPosition(const Position &aPosition);
		void SetPosition(const float aXPosition, const float aYPosition);
		const Position& GetPosition() const;

		void SetOrginPosition(const Position &aPosition);
		void SetOrginPosition(const float aXPosition, const float aYPosition);
		const Position& GetOrginPosition() const ;

		void SetVelocity(const Position &aVelocity);
		void SetVelocity(const float aXVelocity, const float aYVelocity);
		const Position& GetVelocity() const;

		void SetSize(const Size &aSize);
		void SetSize(const float aWidth, const float aHeight);
		const Size& GetSize() const;
	private:
		hgeSprite *mySprite;
		HTEXTURE myTexture;
		Position myPosition;
		Position myVelocity;
		Position myOrginPosition;
		Size mySize;
		HGE *myHge;
	};
}
