#define _CRT_SECURE_NO_WARNINGS 
#include <string.h>
//��������ת����
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
	//���������������Թ������飬�����������
	//Ч��Ϊ��V��ʼ����ֵ��5���������ֵ�ָ���2��ָ���Ԫ��Ϊ��д�ڴ���ǰ���С��
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

