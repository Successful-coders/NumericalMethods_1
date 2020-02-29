#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//using namespace std;//лучше потом не использоать

// надо будет сделать с шаблонами на тип int & double, есть пример в методе
class Sparse_Matrix_CSlR
{
public:
	int sizeMatrix = 0;
	// Динамику?
	double *di = new double[] ;
	double *autr = new double[];
	double *altr = new double[];
	int *jptr = new int[];
	int *iptr = new int[];
	Sparse_Matrix_CSlR(const std::string& PATH);
};

//class Reader
//{
//public:
//
//private:
//
//};

Sparse_Matrix_CSlR::Sparse_Matrix_CSlR(const std:: string &PATH)
{
	//размер матрицы
	int N = 0;
	std::ifstream Reader(PATH + "size.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File size.bin was not found...");
	Reader.read((char*)&N, sizeof(N));
	Reader.close();
	//di
	Reader.open(PATH + "di.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File di.bin was not found...");
	di.resize(N);
	for (int i = 0; i < N; i++)
		Reader.read((char*)&di[i], sizeof(double));
	Reader.close();
	//iptr
	Reader.open(PATH + "iptr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File iptr.bin was not found...");
	iptr.resize(N + 1);
	for (int i = 0; i < N + 1; i++)
		Reader.read((char*)&iptr[i], sizeof(int));
	Reader.close();
	//jptr
	Reader.open(PATH + "jptr.bin", std::ios::binary);
	if (!Reader.is_open())
		throw std::exception("File jptr.bin was not found...");
	int JPTR_SIZE = iptr[N] - 1;
	jptr.resize(JPTR_SIZE);
	for (int i = 0; i < JPTR_SIZE; i++)
		Reader.read((char*)&jptr[i], sizeof(int));
	Reader.close();
	/* Аналогично заполняются массивы altr и autr */
}

void TransFullMatrix()
{
	// перевод в полный формат по заданию
}

void MultipFullMatrix()
{
	// умножение плотной матрицы на произвольный вектор
}

void MultipRazrMatrix()
{
	//умножение разреженой матрицы на вектор
}

void FiftenExs()
{
	// пятое задание, хз что там
}
int main()
{
	

	ReadBin(fileName);

}