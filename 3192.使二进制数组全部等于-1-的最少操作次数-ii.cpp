/*
 * @lc app=leetcode.cn id=3192 lang=cpp
 *
 * [3192] 使二进制数组全部等于 1 的最少操作次数 II
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0 && res % 2 == 0)
            {
                res++;
            }
            if (nums[i] == 1 && res % 2 == 1)
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
