#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <chrono>
#include "MatrixCSIR.h"
#include "Matrix.h"

//using namespace std;

std::vector <double> di;
std::vector <double> autr;
std::vector <double> altr;
std::vector <int> jptr;
std::vector <int> iptr;
int sizeMatrix = 0;

void ReadBin(const std::string& PATH)
{
	//размер матрицы
	
	std::ifstream Reader(PATH + "size.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File size.bin was not found...");
	Reader.read((char*)&sizeMatrix, sizeof(sizeMatrix));
	Reader.close();

	//di
	Reader.open(PATH + "di.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File di.bin was not found...");
	di.resize(sizeMatrix);
	for (int i = 0; i < sizeMatrix; i++)
		Reader.read((char*)&di[i], sizeof(double));
	Reader.close();

	//iptr
	Reader.open(PATH + "iptr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File iptr.bin was not found...");
	iptr.resize(sizeMatrix + 1);
	for (int i = 0; i < sizeMatrix + 1; i++)
		Reader.read((char*)&iptr[i], sizeof(int));
	Reader.close();

	//jptr
	Reader.open(PATH + "jptr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File jptr.bin was not found...");
	int JPTR_SIZE = iptr[sizeMatrix] - 1;
	jptr.resize(JPTR_SIZE);
	for (int i = 0; i < JPTR_SIZE; i++)
		Reader.read((char*)&jptr[i], sizeof(int));
	Reader.close();

	//autr
	Reader.open(PATH + "autr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File autr.bin was not found...");
	int AUTR_SIZE = iptr[sizeMatrix] - 1;
	autr.resize(AUTR_SIZE);
	for (int i = 0; i < AUTR_SIZE; i++)
		Reader.read((char*)&autr[i], sizeof(double));
	Reader.close();

	//altr
	Reader.open(PATH + "altr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File altr.bin was not found...");
	int ALTR_SIZE = iptr[sizeMatrix] - 1;
	altr.resize(ALTR_SIZE);
	for (int i = 0; i < JPTR_SIZE; i++)
		Reader.read((char*)&altr[i], sizeof(double));
	Reader.close();
}

//void TestAllMulitplications()
//{
//	sizeMatrix = 7;
//
//	di.clear();
//	di.push_back(9);
//	di.push_back(11);
//	di.push_back(10);
//	di.push_back(9);
//	di.push_back(12);
//	di.push_back(8);
//	di.push_back(8);
//
//	autr.clear();
//	autr.push_back(2);
//	autr.push_back(3);
//	autr.push_back(1);
//	autr.push_back(2);
//	autr.push_back(1);
//	autr.push_back(1);
//	autr.push_back(1);
//	autr.push_back(2);
//	autr.push_back(1);
//
//	altr.clear();
//	altr.push_back(1);
//	altr.push_back(2);
//	altr.push_back(1);
//	altr.push_back(2);
//	altr.push_back(1);
//	altr.push_back(1);
//	altr.push_back(2);
//	altr.push_back(2);
//	altr.push_back(3);
//
//	jptr.clear();
//	jptr.push_back(2);
//	jptr.push_back(1);
//	jptr.push_back(2);
//	jptr.push_back(3);
//	jptr.push_back(1);
//	jptr.push_back(4);
//	jptr.push_back(1);
//	jptr.push_back(2);
//	jptr.push_back(5);
//
//	iptr.clear();
//	iptr.push_back(1);
//	iptr.push_back(1);
//	iptr.push_back(1);
//	iptr.push_back(2);
//	iptr.push_back(5);
//	iptr.push_back(7);
//	iptr.push_back(7);
//	iptr.push_back(10);
//
//	MatrixCSIR matrixCSIR(sizeMatrix, di, autr, altr, jptr, iptr);
//
//	matrixCSIR.Print();
//
//	cout << "******" << endl;
//
//	vector<double> multipliedVector;
//	multipliedVector.push_back(3);
//	multipliedVector.push_back(0);
//	multipliedVector.push_back(1);
//	multipliedVector.push_back(1);
//	multipliedVector.push_back(1);
//	multipliedVector.push_back(1);
//	multipliedVector.push_back(1);
//
//	for (int i = 0; i < multipliedVector.size(); i++)
//	{
//		cout << multipliedVector[i] << endl;
//	}
//
//	cout << "======" << endl;
//
//	vector<double> resultVector = matrixCSIR.MultiplyByVector(multipliedVector);
//
//	for (int i = 0; i < resultVector.size(); i++)
//	{
//		cout << resultVector[i] << endl;
//	}
//
//	cout << endl;
//
//	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Matrix matrix(matrixCSIR);
//
//	cout << endl;
//	matrix.Print();
//
//	cout << "******" << endl;
//
//	for (int i = 0; i < multipliedVector.size(); i++)
//	{
//		cout << multipliedVector[i] << endl;
//	}
//
//	cout << "======" << endl;
//
//	resultVector = matrix.MultiplyByVector(multipliedVector);
//
//	for (int i = 0; i < resultVector.size(); i++)
//	{
//		cout << resultVector[i] << endl;
//	}
//}
//
//void TestSimpleMultiplication()
//{
//	vector<vector<double>> testElements;
//	testElements.push_back(vector<double>());
//	testElements.push_back(vector<double>());
//	testElements.push_back(vector<double>());
//
//	testElements[0].push_back(2);
//	testElements[0].push_back(3);
//	testElements[0].push_back(2);
//
//	testElements[1].push_back(0);
//	testElements[1].push_back(1);
//	testElements[1].push_back(5);
//
//	testElements[2].push_back(6);
//	testElements[2].push_back(6);
//	testElements[2].push_back(6);
//
//	Matrix matrix(testElements);
//
//	matrix.Print();
//
//	cout << "******" << endl;
//
//	vector<double> multipliedVector;
//	multipliedVector.push_back(3);
//	multipliedVector.push_back(0);
//	multipliedVector.push_back(1);
//
//	for (int i = 0; i < multipliedVector.size(); i++)
//	{
//		cout << multipliedVector[i] << endl;
//	}
//
//	cout << "======" << endl;
//
//	vector<double> resultVector = matrix.MultiplyByVector(multipliedVector);
//
//	for (int i = 0; i < resultVector.size(); i++)
//	{
//		cout << resultVector[i] << endl;
//	}
//}

double Euklidnorm(vector<double> y)
{
	double EuklResult = 0;
	for (int i = 0; i < sizeMatrix; i++)
	{
		EuklResult += y[i] * y[i];
	}
	double result = sqrt(EuklResult);
	return result;
}

//double MultipleVectorOnVector(vector<double> y)
//{
//	double result= 0;
//	for (int i = 0; i < y.size; i++)
//	{
//		result += y[i] * y[i];
//	}
//	return result;
//}
int main()
{
	ReadBin(""); /// 1 exs
	MatrixCSIR matrixCSIR(sizeMatrix, di, autr, altr, jptr, iptr);

	vector <double> multipleVector;
	for (int i = 0; i < sizeMatrix; i++)
	{
		double element = rand()%100 +(double)rand() / RAND_MAX;
		multipleVector.push_back(element);
	}

	auto start = std::chrono::high_resolution_clock::now();

	matrixCSIR.MultiplyByVector<double>(multipleVector);// 3 exs (a)

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Time multiplication CSlR on vector " << diff.count() << endl;

	Matrix matrix(matrixCSIR);// 2 exs ПРОБЛЕМА С ВЫДЕЛЕНИЕМ ПАМЯТИ

	auto start1 = std::chrono::high_resolution_clock::now();

	matrix.MultiplyByVector(multipleVector);// 3 exs(b)

	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Time multiplication Full matrix on vector " << diff1.count() << endl;

	//////////////////////////////////////////////////////////////////////////////////
	// 5 exs
	vector <int> x;
	x.push_back(1);
	for (int i = 0; i < sizeMatrix-1; i++)
	{
		x.push_back(0);
	}


	///5 (a) exs
	//vector <double> y;
	//while (true)
	//{
	//	y = matrixCSIR.MultiplyByVector(x);
	//	cout << Euklidnorm(y)<<" " << x[0] <<endl;
	//	x[0] = 10 * x[0];
	//}
	//5(b) exs
	vector <double> y;
	while (true)
	{
		y = matrixCSIR.MultiplyByVector(x);
		cout << Euklidnorm(y) << " " << x[0] << endl;
		x[0] = x[0] / 10;
	}
}
