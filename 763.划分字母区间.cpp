/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int count[27] = {0};
        vector<int> res;
        // 记录各字母最远位置
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a'] = i;
        }

        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 找到当前字母的最远位置
            right = max(right, count[s[i] - 'a']);
            if (i == right)
            {
                res.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end
