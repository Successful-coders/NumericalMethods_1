#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "MatrixCSIR.h"

using namespace std;//лучше потом не использоать

int sizeMatrix = 0;
double* di;
double* autr;
double* altr;
int* jptr;
int* iptr;

void ReadBin(char* fileName)
{

}

int main()
{
	char* fileName;

	//reading
	ReadBin(fileName);

	MatrixCSIR matrix(sizeMatrix, di, autr, altr, jptr, iptr);
}