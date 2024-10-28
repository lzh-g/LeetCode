/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int count = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                continue;
            }
            nums[count++] = nums[i];
        }
        return count;
    }
};
// @lc code=end
