/************************************************************************

给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。

请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。



示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/

#include "stdafx.h"

int nextNum(int* nums1, int nums1Size, int* nums2, int nums2Size, int* n1, int* n2)
{
  if (*n1 < nums1Size && *n2 < nums2Size)
  {
    if (nums1[*n1] <= nums2[*n2])
    {
      return nums1[(*n1)++];
    }
    else
    {
      return nums2[(*n2)++];
    }
  }
  else if (*n1 < nums1Size)
  {
    return nums1[(*n1)++];
  }
  else
  {
    return nums2[(*n2)++];
  }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
  int n1 = 0, n2 = 0;
  int count = (nums1Size + nums2Size) / 2;
  if ((nums1Size + nums2Size) % 2)
  {
    count++;
  }

  int first = 0, second = 0;
  while (n1 + n2 < count)
  {
    first = nextNum(nums1, nums1Size, nums2, nums2Size, &n1, &n2);
  }

  if (((nums1Size + nums2Size) % 2) == 0)
  {
    second = nextNum(nums1, nums1Size, nums2, nums2Size, &n1, &n2);
    return (first + second) / 2.f;
  }
  else
  {
    return first;
  }
}

void lc0004()
{
  {
    int nums1[] = { 1, 3 };
    int nums2[] = { 2 };
    double m = findMedianSortedArrays(nums1, 2, nums2, 1);
    assert(m == 2.0);
  }
  {
    int nums1[] = { 1, 2 };
    int nums2[] = { 3, 4 };
    double m = findMedianSortedArrays(nums1, 2, nums2, 2);
    assert(m == 2.5);
  }
}
