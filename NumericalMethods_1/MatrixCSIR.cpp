#include "MatrixCSIR.h"
#include "Matrix.h"
#include <iostream>

MatrixCSIR::MatrixCSIR(int sizeMatrix, vector <double> di, vector <double> autr, vector <double> altr, vector <int> jptr, vector <int> iptr)
{
	MatrixCSIR::size = sizeMatrix;
	MatrixCSIR::di = di;
	MatrixCSIR::autr = autr;
	MatrixCSIR::altr = altr;
	MatrixCSIR::jptr = jptr;
	MatrixCSIR::iptr = iptr;
}

double MatrixCSIR::GetElement(int row, int column)
{
	//диагональный элемент
	if (row == column) return di[row];

	//нижний треугольник
	if (row > column)
	{
		int lineElementsNumber = iptr[row + 1] - iptr[row];
		if (lineElementsNumber == 0) return 0;

		//ищем столбец Column в массиве jptr
		for (int ind = iptr[row] - 1, k = 0; k < lineElementsNumber; ind++, k++)
		{
			if (column == (jptr[ind] - 1))
			{
				return altr[iptr[row] - 1 + k];
			}
		}
	}

	//верхний треугольник
	if (row < column)
	{
		int rowElementsNumber = iptr[column + 1] - iptr[column];
		if (rowElementsNumber == 0) return 0;

		//ищем строку Row в массиве jptr
		for (int ind = iptr[column] - 1, k = 0; k < rowElementsNumber; ind++, k++)
		{
			if (row == (jptr[ind] - 1))
			{
				return autr[iptr[column] - 1 + k];
			}
		}
	}

	return 0;
}

//Matrix MatrixCSIR::Transpose(MatrixCSIR matrixCSIR)
//{
//	Matrix fullMartix(matrixCSIR);
//	return fullMartix;
//}

template <typename T>
vector<double> MatrixCSIR::MultiplyByVector(vector<T> multipliedVector)
{
	if (multipliedVector.size() != size)
	{
		throw "size not equals";
	}

	vector<double> resultVector;
	
	for (int i = 0; i < size; i++)
	{
		resultVector.push_back(di[i] * multipliedVector[i]);
	}
	
	for (int i = 0; i < size; i++)
	{
		for (int j = iptr[i] - 1; j < iptr[i + 1] - 1; j++)
		{
			resultVector[i] += altr[j] * multipliedVector[jptr[j] - 1];
			resultVector[jptr[j] - 1] += multipliedVector[i] * autr[j];
		}
	}

	return resultVector;
}

void MatrixCSIR::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			double element = GetElement(i, j);
			cout << element;
		}
		cout << endl;
	}
}

int MatrixCSIR::Size()
{
	return size;
}
