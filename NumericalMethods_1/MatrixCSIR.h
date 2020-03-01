#pragma once
#include <vector> 

using namespace std;

class MatrixCSIR
{
public:
	MatrixCSIR(int sizeMatrix, vector <double> di, vector <double> autr, vector <double> altr, vector <int> jptr, vector <int> iptr);
	double GetElement(int row, int column);
	//Matrix Transpose(MatrixCSIR matrixCSIR);

	template <typename T>
	vector<double> MultiplyByVector(vector<T> multipliedVector)
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

	void Print();
	int Size();

private:
	int size = 0;

	std::vector <int> jptr;
	std::vector <double> di;
	std::vector <double> autr;
	std::vector <double> altr;
	std::vector <int> iptr;
};
