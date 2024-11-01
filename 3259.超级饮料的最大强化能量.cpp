/*
 * @lc app=leetcode.cn id=3259 lang=cpp
 *
 * [3259] 超级饮料的最大强化能量
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    long long maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB)
    {
        int n = energyDrinkA.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0));
        dp[0][0] = energyDrinkA[0];
        dp[0][1] = energyDrinkB[0];
        for (int i = 1; i < n; i++)
        {
            // 不切换饮料+当前能量 or 切换饮料
            dp[i][0] = max(dp[i - 1][0] + energyDrinkA[i], dp[i - 1][1]);
            dp[i][1] = max(dp[i - 1][1] + energyDrinkB[i], dp[i - 1][0]);
        }

        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};
// @lc code=end