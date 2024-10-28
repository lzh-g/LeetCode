/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // dp[i][0]:当天无股票，dp[i][1]:当天有股票的钱
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(-prices[i], dp[1]);
        }
        return dp[0];
    }
};
// @lc code=end
