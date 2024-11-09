/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 左闭右闭区间
        //  int left = 0, right = nums.size() - 1;
        //  while (left <= right)
        //  {
        //      int middle = left + (right - left) / 2;
        //      if (nums[middle] < target)
        //      {
        //          left = middle + 1;
        //      }
        //      else if (nums[middle] == target)
        //      {
        //          return middle;
        //      }
        //      else
        //      {
        //          right = middle - 1;
        //      }
        //  }
        //  return -1;

        // 左闭右开区间
        int left = 0, right = nums.size();
        while (left < right)
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else if (nums[middle] == target)
            {
                return middle;
            }
            else
            {
                right = middle;
            }
        }
        return -1;
    }
};
// @lc code=end
