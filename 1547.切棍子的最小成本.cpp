/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        // dp[i][j]表示切割木棍端点下标i-1到右端点下标j+1的最小成本
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(m + 2, vector<int>(m + 2));
        for (int i = m; i >= 1; i--)
        {
            for (int j = i; j <= m; j++)
            {
                // 初始化
                dp[i][j] = (i == j) ? 0 : INT_MAX;

                // 从下标k处切开
                for (int k = i; k <= j; k++)
                {
                    dp[i][j] = min(dp[i][k - 1] + dp[k + 1][j], dp[i][j]);
                }
                dp[i][j] += (cuts[j + 1] - cuts[i - 1]);
            }
        }
        return dp[1][m];
    }
};
// @lc code=end
