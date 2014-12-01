#pragma once
template <typename TYPE>
class Vector3
{
public:
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
};
