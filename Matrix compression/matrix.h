#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>

#define ORDER 5
#define TRAN(x,y) y - x - 1//用于对角矩阵主副对角线转化

typedef int ElemType;//可根据需要的数据类型调整

//对称矩阵存储
void SaveSymMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order);

//读取对称矩阵元素
ElemType LoadSymMatrix(ElemType* SaveData, int row, int col, int order);

//上三角矩阵存储
void SaveUTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order);

//下三角矩阵存储
void SaveDTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order/*方阵阶数*/);

//读取上三角矩阵元素
ElemType LoadUTriMatrix(ElemType* SaveData, int row, int col, int order);

//读取下三角矩阵元素
ElemType LoadDTriMatrix(ElemType* SaveData, int row, int col, int order);

//主对角矩阵存储
void SavePriDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide/*对角宽度*/);

//副对角矩阵存储
void SaveSubDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide);

//读取主对角矩阵元素
ElemType LoadPriDiagMatrix(ElemType* SaveData, int row, int col, int wide);

//读取副对角矩阵元素
ElemType LoadSubDiagMatrix(ElemType* SaveData, int row, int col, int wide);

//三元组顺序表类型定义
typedef struct {
	int row, col;//从0开始
	ElemType e;
}Triple;

typedef struct {
	Triple* data;
	int _row, _col, _sum;//从1开始
}TSMatrix;

#define ROW 4
#define COL 6

//矩阵以三元组形式存储
void SaveSparseMatrix(ElemType matrix[ROW][COL], TSMatrix* SaveData);

//读取以三元组存储的矩阵
ElemType LoadSparseMatrix(TSMatrix* SaveData, int row, int col);

//矩阵转置

//直接取-顺序存
void TransSMatrix_TSM(TSMatrix M, TSMatrix T);

//顺序取-直接存->快速转置
void FastTransSMatrix_TSM(TSMatrix M, TSMatrix T);