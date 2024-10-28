/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        if (nums[0] > target)
        {
            return 0;
        }

        // dp[j]表示总和为j的元素组合个数
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0; j <= target; j++)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (j - nums[i] >= 0)
                {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};
// @lc code=end
