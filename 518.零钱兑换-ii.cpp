/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<uint32_t> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end
