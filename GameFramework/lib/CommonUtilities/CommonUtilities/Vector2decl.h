#pragma once
template <typename TYPE>
class Vector2
{
public:
	Vector2();
	union
	{
		TYPE myX;
		TYPE x;
		TYPE r;
		TYPE myR;
	};
	union
	{
		TYPE myY;
		TYPE y;
		TYPE g;
		TYPE myG;
	};
};
template<typename TYPE>
Vector2<TYPE>::Vector2()
{
	myX = 0;
	myY = 0;
}