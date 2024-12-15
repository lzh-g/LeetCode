/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> cnt;
        int res = 0, left = 0;
        for (int right = 0; right < s.size(); right++)
        {
            while (cnt.find(s[right]) != cnt.end())
            {
                cnt.erase(s[left]);
                left++;
            }
            cnt.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
    }
};
// @lc code=end
