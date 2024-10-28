/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res;
        for (auto &&it : s)
        {
            if (res.empty() || res.back() != it)
            {
                res.push_back(it);
            }
            else
            {
                res.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
