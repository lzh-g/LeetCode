/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        // 先搜索
        int left = 0, right = nums.size() - 1;
        while (left <= right)
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
                right = middle - 1;
            }
        }
        return left;
    }
};
// @lc code=end
