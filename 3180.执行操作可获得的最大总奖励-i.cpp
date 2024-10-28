/*
 * @lc app=leetcode.cn id=3180 lang=cpp
 *
 * [3180] 执行操作可获得的最大总奖励 I
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxTotalReward(vector<int> &rewardValues)
    {
        // 每个数只有取or不取两种选择，背包问题
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        int m = rewardValues.back();
        // dp[i]表示总奖励i是否可取
        // dp[i]=dp[i-j]|dp[i]，如果先前的操作可以获得奖励i-j，那么加上j后就能获得奖励i
        // 总奖励一定小于2*max(数组)
        vector<int> dp(2 * m);
        dp[0] = 1;
        // 背包
        for (int x : rewardValues)
        {
            for (int k = 2 * x - 1; k >= x; k--)
            {
                if (dp[k - x])
                {
                    dp[k] = 1;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i] == 1)
            {
                res = i;
            }
        }
        return res;
    }
};
// @lc code=end
