/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        // dp[i][j]:i个0，j个1的最大子集长度
        // dp[i][j]=max(dp[i][j],dp[i-zeroNum][j-oneNum]+1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto &&str : strs)
        {
            int oneNum = 0, zeroNum = 0;
            for (auto &&c : str)
            {
                if (c == '0')
                {
                    zeroNum++;
                }
                else
                {
                    oneNum++;
                }
            }
            // 两个背包，一个背包装0，一个背包装1
            for (int i = m; i >= zeroNum; i--)
            {
                for (int j = n; j >= oneNum; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
