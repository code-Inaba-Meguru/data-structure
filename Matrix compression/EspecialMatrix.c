#include <assert.h>
#include <math.h>
#include "matrix.h"

//∂‘≥∆æÿ’Û(Symmetric matrix)
void SaveSymMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order) {
	assert(matrix && SaveData);
	int row = 0, col = 0, pos = 0;
	for (row = 0; row < order; row++)
		for (col = 0; col <= row; col++)
			SaveData[pos++] = matrix[row][col];
}

ElemType LoadSymMatrix(ElemType* SaveData, int row, int col, int order) {
	assert(SaveData);
	int pos = 0;
	if (row < col)
		LoadSymMatrix(SaveData, col, row, order);
	else {
		pos = row * (row + 1) / 2 + col;
		return SaveData[pos];
	}
}

//»˝Ω«æÿ’Û(triangular matrix)
void SaveUTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order) {
	assert(matrix && SaveData);
	int row = 0, col = 0, pos = 0;
	for (row = 0; row < order; row++)
		for (col = row; col < order; col++)
			SaveData[pos++] = matrix[row][col];
	SaveData[pos] = matrix[1][0];
}

void SaveDTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order/*∑Ω’ÛΩ◊ ˝*/) {
	assert(matrix && SaveData);
	int row = 0, col = 0, pos = 0;
	for (row = 0; row < order; row++)
		for (col = 0; col <= row; col++)
			SaveData[pos++] = matrix[row][col];
	SaveData[pos] = matrix[0][1];
}

ElemType LoadUTriMatrix(ElemType* SaveData, int row, int col, int order) {
	assert(SaveData);
	int pos = row * (order * 2 - row + 1) / 2 + col - row;
	if (row > col)
		return SaveData[order * (order + 1) / 2];
	return SaveData[pos];
}

ElemType LoadDTriMatrix(ElemType* SaveData, int row, int col, int order) {
	assert(SaveData);
	int pos = row * (row + 1) / 2 + col;
	if (row < col)
		return SaveData[order * (order + 1) / 2];
	return SaveData[pos];
}

//∂‘Ω«æÿ’Û
void SavePriDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide/*∂‘Ω«øÌ∂»*/) {
	assert(matrix && SaveData);
	int i = 0, j = 0, pos = 0;
	for (i = 0; i < ORDER; i++)
		for (j = i - (wide - 1) / 2; j <= i + (wide - 1) / 2; j++) {
			//|i - j| <= (wide - 1) / 2
			if (j < 0 || j >= ORDER)
				SaveData[pos++] = 0;
			else
				SaveData[pos++] = matrix[i][j];
		}
}

void SaveSubDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide) {
	assert(matrix && SaveData);
	int i = 0, j = 0, pos = 0;
	for (i = 0; i < ORDER; i++)
		for (j = TRAN(i,ORDER) - (wide - 1) / 2; j <= TRAN(i, ORDER) + (wide - 1) / 2; j++) {
			if (j < 0 || j >= ORDER)
				SaveData[pos++] = 0;
			else
				SaveData[pos++] = matrix[i][j];
		}
}

ElemType LoadPriDiagMatrix(ElemType* SaveData, int row, int col, int wide) {
	assert(SaveData);
	int pos = wide * row + col - row + (wide - 1) / 2;
	if (abs(row - col) <= (wide - 1) / 2)
		return SaveData[pos];
	return (ElemType)0;
}

ElemType LoadSubDiagMatrix(ElemType* SaveData, int row, int col, int wide) {
	assert(SaveData);
	int pos = wide * row + col - (TRAN(row, ORDER)) + (wide - 1) / 2;
	if (abs(TRAN(row, ORDER) - col) <= (wide - 1) / 2)
		return SaveData[pos];
	return (ElemType)0;
}