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
	vector<double> MultiplyByVector(vector<T> multipliedVector);
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
