/*
 * @lc app=leetcode.cn id=3258 lang=cpp
 *
 * [3258] 统计满足K约束的子字符串数量I
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int countKConstraintSubstrings(string s, int k)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int cnt[2] = {0};
            for (int j = i; j < s.size(); j++)
            {
                cnt[s[j] - '0']++;
                if (cnt[0] > k && cnt[1] > k)
                {
                    break;
                }
                res++;
            }
        }
        return res;
    }
};
// @lc code=end