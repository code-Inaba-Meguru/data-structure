#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
//仅作算法原理演示，传参方式需参考数组的创建方式

ElemType SymMatrix[ORDER][ORDER] = {
	{3,6,4,7,8},
	{6,2,8,4,2},
	{4,8,1,6,9},
	{7,4,6,0,5},
	{8,2,9,5,7}
};

ElemType UTriMatrix[ORDER][ORDER] = {
	{ 3 , 6 , 4 , 7 , 8 },
	{'c', 2 , 8 , 4 , 2 },
	{'c','c', 1 , 6 , 9 },
	{'c','c','c', 0 , 5 },
	{'c','c','c','c', 7 }
};

ElemType DTriMatrix[ORDER][ORDER] = {
	{ 3 ,'c','c','c','c'},
	{ 6 , 2 ,'c','c','c'},
	{ 4 , 8 , 1 ,'c','c'},
	{ 7 , 4 , 6 , 0 ,'c'},
	{ 8 , 2 , 9 , 5 , 7 }
};

ElemType PriDiagMatrix[ORDER][ORDER] = {
	{1,2,0,0,0},
	{1,2,3,0,0},
	{0,2,3,4,0},
	{0,0,3,4,5},
	{0,0,0,4,5}
};

ElemType SubDiagMatrix[ORDER][ORDER] = {
	{0,0,0,4,5},
	{0,0,3,4,5},
	{0,2,3,4,0},
	{1,2,3,0,0},
	{1,2,0,0,0}
};

void output(ElemType* SaveData, ElemType(*fuc)(ElemType*, int, int, int)) {
	for (int i = 0; i < ORDER; i++) {
		for (int j = 0; j < ORDER; j++)
			printf("%-3d", fuc(SaveData, i, j, ORDER));
		printf("\n");
	}
}
void view(ElemType* SaveData) {
	for (int i = 0; i < (1 + (ORDER * (ORDER + 1)) / 2); i++)
		printf("%-3d", SaveData[i]);
	printf("\n");
}

int main() {
	ElemType* SaveData = (ElemType*)malloc(sizeof(ElemType) * (1 + (ORDER * (ORDER + 1) / 2)));
	if (!SaveData) {
		printf("overflow\n");
		return 1;
	}
	memset(SaveData, 0, sizeof(ElemType) * (1 + (ORDER * (ORDER + 1) / 2)));
	//测试对称矩阵
	SaveSymMatrix(SymMatrix, SaveData, ORDER);
	view(SaveData);
	output(SaveData, LoadSymMatrix);

	//测试上三角矩阵
	SaveUTriMatrix(UTriMatrix, SaveData, ORDER);
	view(SaveData);
	output(SaveData, LoadUTriMatrix);

	//测试下三角矩阵
	SaveDTriMatrix(DTriMatrix, SaveData, ORDER);
	view(SaveData);
	output(SaveData, LoadDTriMatrix);
	free(SaveData);
	SaveData = NULL;

	int wide = 3;
	ElemType* SaveData2 = (ElemType*)malloc(ORDER * wide*sizeof(ElemType));
	if (!SaveData2) {
		printf("overflow\n");
		return 1;
	}
	memset(SaveData2, 0, ORDER * wide * sizeof(ElemType));
	//测试主对角矩阵
	SavePriDiagMatrix(PriDiagMatrix, SaveData2, wide);
	for (int i = 0; i < ORDER*wide; i++)
		printf("%-3d", SaveData2[i]);
	printf("\n");//查看存储内容
	for (int i = 0; i < ORDER; i++) {
		for (int j = 0; j < ORDER; j++)
			printf("%-3d", LoadPriDiagMatrix(SaveData2, i, j, wide));
		printf("\n");//读取存档
	}

	//测试副对角矩阵
	SaveSubDiagMatrix(SubDiagMatrix, SaveData2, wide);
	for (int i = 0; i < ORDER * wide; i++)
		printf("%-3d", SaveData2[i]);
	printf("\n");//查看存储内容
	for (int i = 0; i < ORDER; i++) {
		for (int j = 0; j < ORDER; j++)
			printf("%-3d", LoadSubDiagMatrix(SaveData2, i, j, wide));
		printf("\n");//读取存档
	}
	free(SaveData2);
	SaveData2 = NULL;
	return 0;
}