/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 贪心
        // int sum = 0;
        // int res = INT32_MIN;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     sum += nums[i];
        //     if (sum > res)
        //     {
        //         res = sum;
        //     }

        //     if (sum <= 0)
        //     {
        //         sum = 0;
        //     }
        // }
        // return res;

        // 动规
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = res < dp[i] ? dp[i] : res;
        }
        return res;
    }
};
// @lc code=end
