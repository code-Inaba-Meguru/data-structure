#include "SeqList.h"

//测试算法正确性
int main() {
	SeqList L;
	ElemType* e = (ElemType*)malloc(sizeof(ElemType));
	InitList(&L);

	for (int i = 1; i <= 10; i++)
		ListInsert(&L, i, i);
	PrintList(L);
	printf("表长为:%d\n", Length(L));

	for (int i = 1; i <= 10; i++)
		ListInsert(&L, i, 0);
	PrintList(L);
	printf("表长为:%d\n", Length(L));

	printf("7是表中的第%d个元素\n", LocateElem(L,7));
	printf("第12个元素是:%d\n", GetElem(L, 12));

	ListDelete(&L, 15, e);
	printf("删除的元素是:%d\n", *e);
	free(e);
	PrintList(L);

	DestroyList(&L);

	return 0;
}