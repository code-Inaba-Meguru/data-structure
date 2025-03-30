#include <math.h>
#include <limits.h>
  //寻找两个正序数组的中位数，时间复杂度限制O(log(m+n))
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if (nums1Size > nums2Size)
		return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
	//递归交换变量确保nums1较短
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
	//此时有nums1[left]<=nums2[j+1],且nums1[right]>b[j]
	int i = left;
	int j = (nums1Size + nums2Size + 1) / 2 - 2 - i;
	int ni = i >= 0 ? nums1[i] : INT_MIN;
	int nj = j >= 0 ? nums2[j] : INT_MIN;
	int ni1 = i + 1 < nums1Size ? nums1[i + 1] : INT_MAX;
	int nj2 = j + 1 < nums2Size ? nums2[j + 1] : INT_MAX;
	int max = fmax(ni, nj);//对左半部分分割中，指针指向元素的较大者
	int min = fmin(ni1, nj2);//对右半部分分割中，指针指向元素的较小者
	return (nums1Size + nums2Size) % 2 ? max : (min + max) / 2.0;
}
//该算法时间复杂度为O(log(min(m,n)))，空间复杂度为O(1)
//思路是利用中位数将正序序列分割为前后长度相等的两部分，使前半部分的最大值小于后半部分最小值
//设定两个指针i,j，在两个数组中完成上述分割,分割使用二分查找