/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
    static constexpr int mod = 1e9 + 07;

public:
    int knightDialer(int n)
    {
        // 思路：第i个号码上拨n次的总数等于i跳到了下一个号码拨n-1次的总数之和
        vector<vector<int>> move = {
            {4, 6},
            {6, 8},
            {7, 9},
            {4, 8},
            {0, 3, 9},
            {},
            {0, 1, 7},
            {2, 6},
            {1, 3},
            {2, 4}};

        // 使用滚动数组实现，第i次的情况仅依赖于i-1次
        // dp[n][x]表示骑士在x单元格上执行n-1次操作时的号码数
        // dp[n][x]=sum(dp[n-1][y]),y表示能从x到y的所有数字
        vector<vector<int>> dp(2, vector<int>(10, 0));
        fill(dp[1].begin(), dp[1].end(), 1);
        for (int i = 2; i <= n; i++)
        {
            int x = i & 1; // i偶x为0，i奇x为1
            for (int j = 0; j < 10; j++)
            {
                // 计算下一次操作的号码数
                dp[x][j] = 0;
                for (auto &&y : move[j])
                {
                    // 这里的dp[x^1][y]就表示上一次在y上的次数
                    dp[x][j] = (dp[x][j] + dp[x ^ 1][y]) % mod;
                }
            }
        }

        int res = 0;
        for (auto &&i : dp[n % 2])
        {
            res = (res + i) % mod;
        }
        return res;
    }
};
// @lc code=end
