#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "MatrixCSIR.h"

//using namespace std;//лучше потом не использоать
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

int main()
{
	char* fileName;
	ReadBin("");

	//MatrixCSIR matrix(sizeMatrix, di, autr, altr, jptr, iptr);
}
