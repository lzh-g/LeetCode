/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 1;
        }

        int res = INT_MIN;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > res)
            {
                res = dp[i];
            }
        }
        return res;
    }
};
// @lc code=end
