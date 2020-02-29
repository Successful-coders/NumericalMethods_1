//#include "MatrixCSIR.h"
//
//MatrixCSIR::MatrixCSIR(int sizeMatrix, double* di, double* autr, double* altr, int* jptr, int* iptr)
//{
//	MatrixCSIR::sizeMatrix = sizeMatrix;
//	MatrixCSIR::di = di;
//	MatrixCSIR::autr = autr;
//	MatrixCSIR::altr = altr;
//	MatrixCSIR::jptr = jptr;
//	MatrixCSIR::iptr = iptr;
//}
//
////метод доступа к элементу матрицы в формате CSlR
////Row – номер строки, Column – номер столбца (начинаются с 0)
//double MatrixCSIR::GetElement(int row, int column)
//{
//	//диагональный элемент
//	if (row == column) return di[row];
//
//	//нижний треугольник
//	if (row > column)
//	{
//		int lineElementsNumber = iptr[row + 1] - iptr[row];
//		if (lineElementsNumber == 0) return 0;
//
//		//ищем столбец Column в массиве jptr
//		for (int ind = iptr[row] - 1, int k = 0; k < lineElementsNumber; ind++, k++)
//			if (column == (jptr[ind] - 1)) return altr[iptr[row] - 1 + k];
//	}
//
//	//верхний треугольник
//	if (row < column)
//	{
//		int rowElementsNumber = iptr[column + 1] - iptr[column];
//		if (rowElementsNumber == 0) return 0;
//		//ищем строку Row в массиве jptr
//		for (int ind = iptr[column] - 1, int k = 0; k < rowElementsNumber; ind++, k++)
//			if (row == (jptr[ind] - 1)) return autr[iptr[column] - 1 + k];
//	}
//}
//
//void MatrixCSIR::TransposeFullMatrix()
//{
//	// перевод в полный формат по заданию
//}
//
//void MatrixCSIR::MultiplyFullMatrix()
//{
//	// умножение плотной матрицы на произвольный вектор
//}
//
//void MatrixCSIR::MultiplyRazrMatrix()
//{
//	//умножение разреженой матрицы на вектор
//}
//
//void MatrixCSIR::FiftenExs()
//{
//	// пятое задание, хз что там
//}