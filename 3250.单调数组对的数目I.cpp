/*
 * @lc app=leetcode.cn id=3250 lang=cpp
 *
 * [3250] 单调数组对的数目I
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int countOfPairs(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i][j]表示arr1[i]=j时，这i+1个数组成的单调数组的个数
        // i>0时，设当前arr1[i]值为v2，需枚举上一位置i-1时arr1取值v1（0<=v1<=v2保证arr1单调非递减），同时要满足arr2单调非递增，即nums[i - 1] - v1 >= nums[i] - v2 >= 0 。
        // 转移方程为dp[i][v2] = sum(dp[i - 1][v1])（v1需同时满足上述两条件），计算累加和时要对1e9+7取余以防溢出，即dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % MOD
        vector<vector<int>> dp(n, vector<int>(51, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; v++)
        {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int v2 = 0; v2 <= nums[i]; v2++)
            {
                // 这里保证v1始终<v2
                for (int v1 = 0; v1 <= v2; v1++)
                {
                    // 这里保证arr2单调非增
                    if (nums[i - 1] - v1 >= nums[i - 1] - v2)
                    {
                        dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for (auto &&v : dp[n - 1])
        {
            res = (res + v) % mod;
        }
        return res;
    }
};
// @lc code=end