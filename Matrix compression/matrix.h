#pragma once
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>

#define ORDER 5
#define TRAN(x,y) y - x - 1//���ڶԽǾ��������Խ���ת��

typedef int ElemType;//�ɸ�����Ҫ���������͵���

//�Գƾ���洢
void SaveSymMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order);

//��ȡ�Գƾ���Ԫ��
ElemType LoadSymMatrix(ElemType* SaveData, int row, int col, int order);

//�����Ǿ���洢
void SaveUTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order);

//�����Ǿ���洢
void SaveDTriMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int order/*�������*/);

//��ȡ�����Ǿ���Ԫ��
ElemType LoadUTriMatrix(ElemType* SaveData, int row, int col, int order);

//��ȡ�����Ǿ���Ԫ��
ElemType LoadDTriMatrix(ElemType* SaveData, int row, int col, int order);

//���ԽǾ���洢
void SavePriDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide/*�Խǿ��*/);

//���ԽǾ���洢
void SaveSubDiagMatrix(ElemType matrix[ORDER][ORDER], ElemType* SaveData, int wide);

//��ȡ���ԽǾ���Ԫ��
ElemType LoadPriDiagMatrix(ElemType* SaveData, int row, int col, int wide);

//��ȡ���ԽǾ���Ԫ��
ElemType LoadSubDiagMatrix(ElemType* SaveData, int row, int col, int wide);

//��Ԫ��˳������Ͷ���
typedef struct {
	int row, col;//��0��ʼ
	ElemType e;
}Triple;

typedef struct {
	Triple* data;
	int _row, _col, _sum;//��1��ʼ
}TSMatrix;

#define ROW 4
#define COL 6

//��������Ԫ����ʽ�洢
void SaveSparseMatrix(ElemType matrix[ROW][COL], TSMatrix* SaveData);

//��ȡ����Ԫ��洢�ľ���
ElemType LoadSparseMatrix(TSMatrix* SaveData, int row, int col);

//����ת��

//ֱ��ȡ-˳���
void TransSMatrix_TSM(TSMatrix M, TSMatrix T);

//˳��ȡ-ֱ�Ӵ�->����ת��
void FastTransSMatrix_TSM(TSMatrix M, TSMatrix T);