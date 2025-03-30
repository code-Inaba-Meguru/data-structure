#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
//罗马数字转整数
typedef struct {
	char Roma;
	int val;
}RomaNum;
int romanToInt(char* s)
{
	int sum = 0, i = 0, j = 0;
	RomaNum I, V, X, L, C, D, M;
	I.Roma = 'I', I.val = 1;
	V.Roma = 'V', V.val = 5;
	X.Roma = 'X', X.val = 10;
	L.Roma = 'L', L.val = 50;
	C.Roma = 'C', C.val = 100;
	D.Roma = 'D', D.val = 500;
	M.Roma = 'M', M.val = 1000;
	RomaNum Rnum[10] = { I,I,V,X,X,L,C,C,D,M };
	//利用罗马数字特性构建数组，方便后续计算
	//效果为从V开始，数值含5的罗马数字的指针减2所指向的元素为可写在大数前面的小数
	for (i = strlen(s) - 1; i >= 0; i--)
	{
		for (j = 0; j <= 9; j++)
		{
			if (s[i] == Rnum[j].Roma)
				break;
		}
		sum += Rnum[j].val;
		if (i >= 1 && j >= 2 && s[i - 1] == Rnum[j - 2].Roma) {
			sum -= Rnum[j - 2].val;
			i--;
		}
	}
	return sum;
}

