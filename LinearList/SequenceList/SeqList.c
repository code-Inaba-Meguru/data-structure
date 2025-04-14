#include "SeqList.h"

void Error(const char* s) {
	printf("%s\n", s);
	exit(1);
}

void InitList(SeqList* L) {
	L->data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
	if (!L->data)
		Error("Overflow!");
	L->length = 0;
	L->MaxSize = InitSize;
}

int Length(SeqList L) {
	return L.length ;
}

int LocateElem(SeqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) 
		if (L.data[i] == e)
			return i+1;
	return 0;
}

ElemType GetElem(SeqList L, int i) {
	if (i<1 || i>L.length)
		Error("Position Error!");
	return L.data[i-1];
}

void Increasement(SeqList* L) {
	ElemType* newlist = (ElemType*)malloc(sizeof(ElemType) * (InitSize + IncreaseSize));
	if (!newlist)
		Error("Overflow!");
	for (int i = 0; i < L->length; i++)
		newlist[i] = L->data[i];
	free(L->data);
	L->data = newlist;
	L->MaxSize += IncreaseSize;
}

void ListInsert(SeqList* L, int i, ElemType e) {
	if (i < 1 || i > L->length + 1)
		Error("Position Error!");
	if (L->length >= L->MaxSize)
		Increasement(L);
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e, ++(L->length);
}

void ListDelete(SeqList* L, int i, ElemType* e) {
	if (i < 1 || i > L->length)
		Error("Position Error!");
	*e = L->data[i - 1];
	for (int j = i; j < L->length; j++)
		L->data[j - 1] = L->data[j];
	--(L->length);
}

void PrintList(SeqList L) {
	for (int i = 0; i < L.length; i++)
		printf("%d\t", L.data[i]);
	printf("\n");
}

bool Empty(SeqList L) {
	if (L.length)
		return true;
	return false;
}

void DestroyList(SeqList* L) {
	free(L->data);
	L->data = NULL;
}