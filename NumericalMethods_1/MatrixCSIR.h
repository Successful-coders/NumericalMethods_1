#pragma once

class MatrixCSIR
{
public:
	MatrixCSIR(int sizeMatrix, double* di, double* autr, double* altr, int* jptr, int* iptr);

	double GetElement(int row, int column);
	void TransposeFullMatrix();
	void MultiplyFullMatrix();
	void MultiplyRazrMatrix();
	void FiftenExs();

private:
	int sizeMatrix = 0;

	double* di;
	double* autr;
	double* altr;
	int* jptr;
	int* iptr;
};