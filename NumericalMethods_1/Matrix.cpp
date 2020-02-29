#include "Matrix.h"

Matrix::Matrix(vector<vector<double>> elements)
{
	Matrix::elements = elements;
}

Matrix::Matrix(MatrixCSIR matrixCSIR)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			elements[i][j] = matrixCSIR.GetElement(i, j);
		}
	}
}

double Matrix::GetElement(int line, int column)
{
	return elements[line][column];
}

vector<double> Matrix::MultiplyByVector(vector<double> multipliedVector)
{
	vector<double> resultVector;

	for (int i = 0; i < size; i++)
	{
		resultVector.push_back(0);
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			resultVector[i] += (elements[i][j] * multipliedVector[j]);
		}
	}

	return resultVector;
}
