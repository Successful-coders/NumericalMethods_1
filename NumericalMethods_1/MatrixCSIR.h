#pragma once
<<<<<<< HEAD
#include <vector> 

using namespace std;
=======
#include <vector>
>>>>>>> dbd939ce70e765a9efeea2aab60c3cb81b621067

class MatrixCSIR
{
public:
	//MatrixCSIR(int sizeMatrix, std::vector <double> di, std::vector <double> autr, std::vector <double> altr, std::vector <int> jptr, std::vector <int> iptr); рср ньхайю
	double GetElement(int row, int column);
	void TransposeFullMatrix();
	void MultiplyFullMatrix();
	vector<double> MultiplySparseMatrixByVector(vector<double> multipliedVector);
	void FiftenExs();

private:
<<<<<<< HEAD
	int size = 0;
=======
	int sizeMatrix = 0;
	std::vector <double> di;
	std::vector <double> autr;
	std::vector <double> altr;
	std::vector <int> jptr;
	std::vector <int> iptr;
};
>>>>>>> dbd939ce70e765a9efeea2aab60c3cb81b621067

