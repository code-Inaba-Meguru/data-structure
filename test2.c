#include <math.h>
#include <limits.h>
  //Ѱ�����������������λ����ʱ�临�Ӷ�����O(log(m+n))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1Size > nums2Size)
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	//�ݹ齻������ȷ��nums1�϶�
	int left = -1, right = nums1Size;
	while (left + 1 < right)
	{
		int i = (left + right) / 2;
		int j = (nums1Size + nums2Size + 1) / 2 - 2 - i;
		if (nums1[i] <= nums2[j + 1])
			left = i;
		else
			right = i;
	}
	//��ʱ��nums1[left]<=nums2[j+1],��nums1[right]>b[j]
	int i = left;
	int j = (nums1Size + nums2Size + 1) / 2 - 2 - i;
	int ni = i >= 0 ? nums1[i] : INT_MIN;
	int nj = j >= 0 ? nums2[j] : INT_MIN;
	int ni1 = i + 1 < nums1Size ? nums1[i + 1] : INT_MAX;
	int nj2 = j + 1 < nums2Size ? nums2[j + 1] : INT_MAX;
	int max = fmax(ni, nj);//����벿�ַָ��У�ָ��ָ��Ԫ�صĽϴ���
	int min = fmin(ni1, nj2);//���Ұ벿�ַָ��У�ָ��ָ��Ԫ�صĽ�С��
	return (nums1Size + nums2Size) % 2 ? max : (min + max) / 2.0;
}
//���㷨ʱ�临�Ӷ�ΪO(log(min(m,n)))���ռ临�Ӷ�ΪO(1)
//˼·��������λ�����������зָ�Ϊǰ�󳤶���ȵ������֣�ʹǰ�벿�ֵ����ֵС�ں�벿����Сֵ
//�趨����ָ��i,j����������������������ָ�,�ָ�ʹ�ö��ֲ���