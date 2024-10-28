/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }
            nums[count++] = nums[i];
        }
        for (size_t i = count; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }
};
// @lc code=end
