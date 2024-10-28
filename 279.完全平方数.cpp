/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        for (int j = 0; j <= n; j++)
        {
            for (int i = 1; i * i <= j; i++)
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
