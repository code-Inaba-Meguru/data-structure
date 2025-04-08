#include "matrix.h"

//��m * n�ľ����У���t������Ԫ�أ���delta = t / (m * n)Ϊ�����ϡ�����ӣ�һ��delta <= 0.05Ϊϡ�����
//ʹ����Ԫ���洢ϡ�����

//ϡ�����洢--��Ԫ��
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

//ֱ��ȡ-˳���
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
//ʱ�临�Ӷ�ΪO(M._col * M._sum),һ�����ת���㷨ʱ�临�Ӷ�ΪO(M.row * M.col)
//����Ԫ�϶�ʱ����һ������㷨

//˳��ȡ-ֱ�Ӵ�->����ת��
void FastTransSMatrix_TSM(TSMatrix M, TSMatrix T) {
	int* num = (int*)malloc(sizeof(int) * M._col);//�洢����Mÿ�з���Ԫ�ظ���
	int* pos = (int*)malloc(sizeof(int) * M._col);//ָʾ����Mÿ�е�һ������Ԫ����T.data��λ��
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