#pragma once
#include <vector>

class MatrixCSIR
{
public:
	//MatrixCSIR(int sizeMatrix, std::vector <double> di, std::vector <double> autr, std::vector <double> altr, std::vector <int> jptr, std::vector <int> iptr); рср ньхайю
	double GetElement(int row, int column);
	void TransposeFullMatrix();
	void MultiplyFullMatrix();
	void MultiplyRazrMatrix();
	void FiftenExs();

private:
	int sizeMatrix = 0;
	std::vector <double> di;
	std::vector <double> autr;
	std::vector <double> altr;
	std::vector <int> jptr;
	std::vector <int> iptr;
};

