#pragma once
namespace CommonUtilities
{
	template<typename Type>
	class Matrix44
	{
	public:
		Type myMatrix[16];

		Matrix44();
		Matrix44(const Matrix44<Type> &aMatrix);
		~Matrix44();

		Matrix44<Type>& operator=(const Matrix44<Type> &aMatrix);

		static Matrix44<Type> CreateRotateAroundX(Type aAngleInRadians);
		static Matrix44<Type> CreateRotateAroundY(Type aAngleInRadians);
		static Matrix44<Type> CreateRotateAroundZ(Type aAngleInRadians);

		static Matrix44<Type> Transpose(const Matrix44<Type> &aMatrixToTranspose);
	};
	template<typename Type>
	Matrix44<Type>::Matrix44()
	{
		for (int i = 0; i < 16; ++i)
		{
			if (i == 0 || i == 5 || i == 10 || i== 15)
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
	Matrix44<Type>::Matrix44(const Matrix44<Type> &aMatrix)
	{
		for (int i = 0; i < 16; ++i)
		{
			myMatrix[i] = aMatrix.myMatrix[i];
		}
	}
	template<typename Type>
	Matrix44<Type>::~Matrix44()
	{

	}
	template<typename Type>
	Matrix44<Type>& Matrix44<Type>::operator=(const Matrix44<Type> &aMatrix)
	{
		for (int i = 0; i < 16; ++i)
		{
			myMatrix[i] = aMatrix.myMatrix[i];
		}
		return *this;
	}
	template<typename Type>
	Matrix44<Type> Matrix44<Type>::CreateRotateAroundX(Type aAngleInRadians)
	{
		Matrix44<Type>rotateMatrix;
		for (int i = 0; i < 16; ++i)
		{
			if (i == 0 || i == 15)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 5 || i == 10)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 6)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else if (i == 9)
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
	Matrix44<Type> Matrix44<Type>::CreateRotateAroundY(Type aAngleInRadians)
	{
		Matrix44<Type>rotateMatrix;
		for (int i = 0; i < 9; ++i)
		{
			if (i == 5 || i == 15)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 0 || i == 10)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 2)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else if (i == 8)
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
	Matrix44<Type> Matrix44<Type>::CreateRotateAroundZ(Type aAngleInRadians)
	{
		Matrix44<Type>rotateMatrix;
		for (int i = 0; i < 9; ++i)
		{
			if (i == 10 || i == 15)
			{
				rotateMatrix.myMatrix[i] = 1;
			}
			else if (i == 0 || i == 5)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(cos(aAngleInRadians));
			}
			else if (i == 1)
			{
				rotateMatrix.myMatrix[i] = static_cast<Type>(sin(aAngleInRadians));
			}
			else if (i == 4)
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
	Matrix44<Type> Matrix44<Type>::Transpose(const Matrix44<Type> &aMatrixToTranspose)
	{
		Matrix44<Type> transposedMatrix;

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				transposedMatrix.myMatrix[j + (i * 4)] = aMatrixToTranspose.myMatrix[i + (j * 4)];
			}
		}

		return transposedMatrix;
	}
} namespace CU = CommonUtilities;