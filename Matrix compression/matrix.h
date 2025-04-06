#pragma once

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