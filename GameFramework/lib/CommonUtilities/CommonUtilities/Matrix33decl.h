#pragma once
#include "Matrix44decl.h"
#include <math.h>

namespace CommonUtilities
{
	template<typename Type>
	class Matrix33
	{
	public:
		Type myMatrix[9];

		Matrix33();
		Matrix33(const Matrix33<Type> &aMatrix);
		Matrix33(Matrix44<Type> &aMatrix);
		~Matrix33();

		Matrix33<Type>& operator=(const Matrix33<Type> &aMatrix);

		static Matrix33<Type> CreateRotateAroundX(Type aAngleInRadians);
		static Matrix33<Type> CreateRotateAroundY(Type aAngleInRadians);
		static Matrix33<Type> CreateRotateAroundZ(Type aAngleInRadians);
		
		static Matrix33<Type> Transpose(const Matrix33<Type> &aMatrixToTranspose);
	};
	template<typename Type>
	Matrix33<Type>::Matrix33()
	{
		for (int i = 0; i < 9; ++i)
		{
			if (i == 0 || i == 4 || i == 8)
			{
				myMatrix[i] = 1;
			}
			else
			{
				myMatrix[i] = 0;
			}
		}
	}
	template<typename Type>
	Matrix33<Type>::Matrix33(const Matrix33<Type> &aMatrix)
	{
		for (int i = 0; i < 9; ++i)
		{
			myMatrix[i] = aMatrix.myMatrix[i];
		}
	}
	template<typename Type>
	Matrix33<Type>::Matrix33(Matrix44<Type> &aMatrix)
	{
		int dataCounter = 0;
		for (int i = 0; i < 11; ++i)
		{
			if (i != 3 || i != 7)
			{
				myMatrix[dataCounter] = aMatrix.myMatrix[i];
				++dataCounter;
			}
		}
	}
	template<typename Type>
	Matrix33<Type>::~Matrix33()
	{

	}
	template<typename Type>
	Matrix33<Type>& Matrix33<Type>::operator=(const Matrix33<Type> &aMatrix)
	{
		for (int i = 0; i < 9; ++i)
		{
			myMatrix[i] = aMatrix.myMatrix[i];
		}
		return *this;
	}
	template<typename Type>
	Matrix33<Type> Matrix33<Type>::CreateRotateAroundX(Type aAngleInRadians)
	{
		Matrix33<Type>rotateMatrix;
		for (int i = 0; i < 9; ++i)
		{
			if (i == 0)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 4 || i == 8)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 5)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else if (i == 7)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(-sin(aAngleInRadians));
			}
			else
			{
				rotateMatrix.myMatrix[i] = 0;
			}
		}
		return rotateMatrix;
	}
	template<typename Type>
	Matrix33<Type> Matrix33<Type>::CreateRotateAroundY(Type aAngleInRadians)
	{
		Matrix33<Type>rotateMatrix;
		for (int i = 0; i < 9; ++i)
		{
			if (i == 4)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 0 || i == 8)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 2)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(-sin(aAngleInRadians));
			}
			else if (i == 6)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else
			{
				rotateMatrix.myMatrix[i] = 0;
			}
		}
		return rotateMatrix;
	}
	template<typename Type>
	Matrix33<Type> Matrix33<Type>::CreateRotateAroundZ(Type aAngleInRadians)
	{
		Matrix33<Type>rotateMatrix;
		for (int i = 0; i < 9; ++i)
		{
			if (i == 8)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 0 || i == 4)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 1)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else if (i == 3)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(-sin(aAngleInRadians));
			}
			else
			{
				rotateMatrix.myMatrix[i] = 0;
			}
		}
		return rotateMatrix;
	}
	template<typename Type>
	Matrix33<Type> Matrix33<Type>::Transpose(const Matrix33<Type> &aMatrixToTranspose)
	{
		Matrix33<Type> transposedMatrix;
		
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				transposedMatrix.myMatrix[j + (i * 3)] = aMatrixToTranspose.myMatrix[i + (j * 3)];
			}
		}

		return transposedMatrix;
	}
} namespace CU = CommonUtilities;