/************************************************************************

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。



示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

************************************************************************/

#include "stdafx.h"

pair<int, int> twoSum(const vector<int>& nums, int target)
{
  map<int, int> bu;
  for (int i = 0; i < (int)nums.size(); i++)
  {
    map<int, int>::iterator it = bu.find(nums[i]);
    if (it == bu.end())
    {
      bu.insert(make_pair(target - nums[i], i));
    }
    else
    {
      return make_pair(it->second, i);
    }
  }
  return make_pair(-1, -1);
}

void lc0001()
{
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(11);
  nums.push_back(16);
  nums.push_back(27);
  nums.push_back(36);
  nums.push_back(55);
  nums.push_back(58);
  int target = 38;

  pair<int, int> r = twoSum(nums, target);
  cout << r.first << " " << r.second;
  assert(r.first == 2);
  assert(r.second == 4);
}
