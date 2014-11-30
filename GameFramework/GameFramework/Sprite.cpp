#include "Sprite.h"

RPG::Sprite::Sprite()
{
	myHge = nullptr;
}

RPG::Sprite::~Sprite()
{
	
}

void RPG::Sprite::Init(HGE *aHge, std::string aFileName, float aXPosition, float aYPosition, float aWidth, float aHeight)
{
	myHge = aHge;
	myWidth = aWidth;
	myHeight = aHeight;
	myTexture = myHge->Texture_Load(aFileName.c_str());
	myQuad.tex = myTexture;

	myQuad.v[0].tx = aXPosition;
	myQuad.v[1].tx = aXPosition + myWidth;
	myQuad.v[2].tx = aXPosition + myWidth;
	myQuad.v[3].tx = aXPosition;

	myQuad.v[0].ty = aYPosition;
	myQuad.v[1].ty = aYPosition;
	myQuad.v[2].ty = aYPosition + myHeight;
	myQuad.v[3].ty = aYPosition + myHeight;

	myQuad.v[0].z = 0.5f;
	myQuad.v[1].z = 0.5f;
	myQuad.v[2].z = 0.5f;
	myQuad.v[3].z = 0.5f;

	myQuad.v[0].col = 0xffffffff;
	myQuad.v[1].col = 0xffffffff;
	myQuad.v[2].col = 0xffffffff;
	myQuad.v[3].col = 0xffffffff;

	myQuad.blend = BLEND_DEFAULT;
}

void RPG::Sprite::Render(float aXPosition, float aYPosition)
{
	myQuad.v[0].x = aXPosition;
	myQuad.v[1].x = aXPosition + myWidth;
	myQuad.v[2].x = aXPosition + myWidth;
	myQuad.v[3].x = aXPosition;

	myQuad.v[0].y = aYPosition;
	myQuad.v[1].y = aYPosition;
	myQuad.v[2].y = aYPosition + myHeight;
	myQuad.v[3].y = aYPosition + myHeight;

	myHge->Gfx_RenderQuad(&myQuad);
}

void RPG::Sprite::Filp(bool aXFilp, bool aYFlip)
{
	float tx, ty;

	if (aXFilp == true)
	{
		tx = myQuad.v[0].tx; myQuad.v[0].tx = myQuad.v[1].tx; myQuad.v[1].tx = tx;
		ty = myQuad.v[0].ty; myQuad.v[0].ty = myQuad.v[1].ty; myQuad.v[1].ty = ty;
		tx = myQuad.v[3].tx; myQuad.v[3].tx = myQuad.v[2].tx; myQuad.v[2].tx = tx;
		ty = myQuad.v[3].ty; myQuad.v[3].ty = myQuad.v[2].ty; myQuad.v[2].ty = ty;

		aXFilp = !aXFilp;
	}

	if (aYFlip == true)
	{
		tx = myQuad.v[0].tx; myQuad.v[0].tx = myQuad.v[3].tx; myQuad.v[3].tx = tx;
		ty = myQuad.v[0].ty; myQuad.v[0].ty = myQuad.v[3].ty; myQuad.v[3].ty = ty;
		tx = myQuad.v[1].tx; myQuad.v[1].tx = myQuad.v[2].tx; myQuad.v[2].tx = tx;
		ty = myQuad.v[1].ty; myQuad.v[1].ty = myQuad.v[2].ty; myQuad.v[2].ty = ty;

		aYFlip = !aYFlip;
	}
}
