#pragma once
#include <vector> 

using namespace std;

class MatrixCSIR
{
public:
	MatrixCSIR(int sizeMatrix, double* di, double* autr, double* altr, int* jptr, int* iptr);

	double GetElement(int row, int column);
	void TransposeFullMatrix();
	void MultiplyFullMatrix();
	vector<double> MultiplySparseMatrixByVector(vector<double> multipliedVector);
	void FiftenExs();

private:
	int size = 0;

	double* di;
	double* autr;
	double* altr;
	int* jptr;
	int* iptr;
};