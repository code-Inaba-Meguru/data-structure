#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

#define InitSize 10
typedef struct {
	ElemType* data;
	int MaxSize, length;
}SeqList;

//基本操作
//初始化表，构建一个空的顺序表
void InitList(SeqList* L); 

//求表长，返回L的长度即数据元素的个数
int Length(SeqList L); 

//按值查找，在L中找到具有给定关键字值的元素的序数（1,2,3,4...）
int LocateElem(SeqList L, ElemType e); 

//按位置查找，获取L中第i个位置元素的值(i = 1,2,3,4...)
ElemType GetElem(SeqList L, int i); 

//插入，在L中第i个位置插入指定元素e(i = 1,2,3,4...)
void ListInsert(SeqList* L, int i, ElemType e);

//删除，删除L中第i个元素，用e返回被删除元素的值(i = 1,2,3,4...)
void ListDelete(SeqList* L, int i, ElemType* e);

//依次输出L的所有元素值
void PrintList(SeqList L);

//判空，L为空表返回true，否则返回false
bool Empty(SeqList L);

//销毁顺序表并释放L占用的内存空间
void DestroyList(SeqList* L);

//辅助操作
//顺序表空间不足时用来扩容
#define IncreaseSize 10
void Increasement(SeqList* L);

//发现异常值时结束函数并给出错误信息
void Error(const char* s);