/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    // 构造next数组
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            // 前后缀不相同
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            // 前后缀相同
            if (s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle)
    {
        // KMP算法
        if (needle.size() == 0)
        {
            return 0;
        }
        vector<int> next(needle.size());
        getNext(&next[0], needle);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j >= 0 && haystack[i] != needle[j + 1])
            {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1])
            {
                j++;
            }
            if (j == (needle.size() - 1))
            {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// @lc code=end
