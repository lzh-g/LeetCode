/*
 * @lc app=leetcode.cn id=3216 lang=cpp
 *
 * [3216] 交换后字典序最小的字符串
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    string getSmallestString(string s)
    {
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (((s[i] - '0') % 2 == (s[i + 1] - '0') % 2) && (s[i] - '0') > (s[i + 1] - '0'))
            {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
// @lc code=end
