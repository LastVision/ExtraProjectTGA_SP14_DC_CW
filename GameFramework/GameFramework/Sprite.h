#pragma once
#include <hge.h>
#include <string>
namespace RPG
{
	class Sprite
	{
	public:
		Sprite();
		~Sprite();

		void Init(HGE *aHge, std::string aFileName, float aXPosition, float aYPosition, float aWidth, float aHeight);
		void Render(float aXPosition, float aYPosition);
		void Filp(bool aXFilp, bool aYFlip);
	private:
		HTEXTURE myTexture;
		hgeQuad myQuad;
		HGE *myHge;
		float myWidth;
		float myHeight;
	};
}