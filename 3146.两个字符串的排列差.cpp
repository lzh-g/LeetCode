/*
 * @lc app=leetcode.cn id=3146 lang=cpp
 *
 * [3146] 两个字符串的排列差
 */
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int pos = t.find(s[i]);
            sum += abs(pos - i);
        }
        return sum;
    }
};
// @lc code=end
