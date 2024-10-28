/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int j = 1; j <= s.size(); j++) // 遍历背包
        {
            for (int i = 0; i < j; i++) // 遍历物品
            {
                string word = s.substr(i, j - i);
                if (wordSet.find(word) != wordSet.end() && dp[i])
                {
                    dp[j] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
