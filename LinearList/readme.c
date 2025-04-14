//线性表基本操作
InitList(&L); //初始化表，构建一个空的线性表
Length(L); //求表长，返回L的长度即数据元素的个数
LocateElem(L, e); //按值查找，在L中找到具有给定关键字值的元素
GetElem(L, i); //按位置查找，获取L中第i个位置元素的值
ListInsert(&L, i, &e);//插入，在L中第i个位置插入指定元素e
ListDelete(&L, i, &e);//删除，删除L中第i个元素，用e返回被删除元素的值
PrintList(L);//依次输出L的所有元素值
Empty(L);//判空，L为空表返回true，否则返回false
DestroyList(L);//销毁线性表并释放L占用的内存空间