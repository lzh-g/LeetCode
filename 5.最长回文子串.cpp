/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int len = 0;
        int res_i = 0, res_j = 0;
        string res;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        dp[i][j] = j - i + 1;
                    }
                    else if (dp[i + 1][j - 1] > 0)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (dp[i][j] > len)
                {
                    len = dp[i][j];
                    res_i = i;
                    res_j = j;
                }
            }
        }
        for (int k = res_i; k <= res_j; k++)
        {
            res.push_back(s[k]);
        }
        return res;
    }
};
// @lc code=end
