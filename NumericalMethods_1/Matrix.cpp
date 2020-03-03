#include "Matrix.h"
#include <iostream>

Matrix::Matrix(vector<vector<double>> elements)
{
	Matrix::elements = elements;
	size = elements.size();
}

Matrix::Matrix(MatrixCSIR matrixCSIR)
{
	size = matrixCSIR.Size();

	std::vector < std::vector < double>>elements;

	for (int i = 0; i < size; i++) {

		elements.push_back(std::vector<double>());

		for (int j = 0; j < size; j++) {

			double s = matrixCSIR.GetElement(i, j);

			elements.back().push_back(s);

		}

	}
	Matrix::elements = elements;
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

void Matrix::Print()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << elements[i][j];
		}
		cout << endl;
	}
}
