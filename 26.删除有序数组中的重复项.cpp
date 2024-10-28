/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            nums[k++] = nums[i];
        }
        return k;
    }
};
// @lc code=end
