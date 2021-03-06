#pragma once
template <typename TYPE>
class Vector4
{
public:
	Vector4();
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
	union
	{
		TYPE myZ;
		TYPE z;
		TYPE b;
		TYPE myB;
	};
	union
	{
		TYPE myW;
		TYPE w;
		TYPE a;
		TYPE myA;
	};
};
template<typename TYPE>
Vector4<TYPE>::Vector4()
{
	myX = 0;
	myY = 0;
	myZ = 0;
	myW = 0;
}