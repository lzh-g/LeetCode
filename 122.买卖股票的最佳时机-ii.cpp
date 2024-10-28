/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // // 贪心，profit表示每天的利润，只取正利润
        // int res = 0;
        // vector<int> profit(prices.size() - 1, 0);
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     profit[i - 1] = prices[i] - prices[i - 1];
        //     if (profit[i - 1] > 0)
        //     {
        //         res += profit[i - 1];
        //     }
        // }
        // return res;

        // 动规
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }
        return dp[prices.size() - 1][0];
    }
};
// @lc code=end
