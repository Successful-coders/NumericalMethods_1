#pragma once
#include <vector>
#include "MatrixCSIR.h"

using namespace std;

class Matrix
{
public:
	Matrix(vector<vector<double>> elements);
	Matrix(MatrixCSIR matrixCSIR);
	double GetElement(int line, int row);
	vector<double> MultiplyByVector(vector<double> multipliedVector);
	void Print();

private:
	int size;

	vector<vector<double>> elements;
};