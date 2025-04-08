#include "matrix.h"

//在m * n的矩阵中，有t个非零元素，称delta = t / (m * n)为矩阵的稀疏因子，一般delta <= 0.05为稀疏矩阵
//使用三元组表存储稀疏矩阵

//稀疏矩阵存储--三元组
void SaveSparseMatrix(ElemType matrix[ROW][COL], TSMatrix* SaveData) {
	int i = 0, j = 0, pos = 0;
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			if (matrix[i][j]) {
				SaveData->data[pos].e = matrix[i][j];
				SaveData->data[pos].row = i;
				SaveData->data[pos].col = j;
				pos++;
			}
	SaveData->_sum = pos, SaveData->_row = ROW, SaveData->_col = COL;
}

ElemType LoadSparseMatrix(TSMatrix* SaveData, int row, int col) {
	for (int i = 0; i < SaveData->_sum; i++)
		if (SaveData->data[i].row == row && SaveData->data[i].col == col)
			return SaveData->data[i].e;
	return (ElemType)0;
}

//直接取-顺序存
void TransSMatrix_TSM(TSMatrix M, TSMatrix T) {
	T._row = M._col, T._col = M._row, T._sum = M._sum;
	if (T._sum) {
		int pt = 0;
		for (int i = 0; i < M._col; i++)
			for (int pm = 0; pm < M._sum; pm++)
				if (M.data[pm].col == i) {
					T.data[pt].row = M.data[pm].col;
					T.data[pt].col = M.data[pm].row;
					T.data[pt].e = M.data[pm].e;
					pt++;
				}
	}
}
//时间复杂度为O(M._col * M._sum),一般矩阵转置算法时间复杂度为O(M.row * M.col)
//非零元较多时劣于一般矩阵算法

//顺序取-直接存->快速转置
void FastTransSMatrix_TSM(TSMatrix M, TSMatrix T) {
	int* num = (int*)malloc(sizeof(int) * M._col);//存储矩阵M每列非零元素个数
	int* pos = (int*)malloc(sizeof(int) * M._col);//指示矩阵M每列第一个非零元素在T.data的位置
	if (!num || !pos) {
		printf("overflow\n");
		return;
	}
	T._row = M._col, T._col = M._row, T._sum = M._sum;
	if (T._sum) {
		memset(num, 0, sizeof(int) * M._col);
		for (int i = 0; i < M._sum; i++)
			++num[M.data[i].col];
		pos[0] = 0;
		for (int i = 1; i < M._sum; i++)
			pos[i] = pos[i - 1] + num[i - 1];
		for (int i = 0; i < M._sum; i++) {
			int j = M.data[i].col;
			int k = pos[j];
			T.data[k].row = M.data[i].col;
			T.data[k].col = M.data[i].row;
			T.data[k].e = M.data[i].e;
			++pos[j];
		}
	}
}