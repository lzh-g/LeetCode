/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        // dp[i][j]为检索到字符i和j时，i~j的字符串是否为回文串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1)
                    {
                        res++;
                        dp[i][j] = true;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
