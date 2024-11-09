/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        // 思路：算出p的字母次数，然后遍历s
        vector<int> count(26, 0);
        // 统计p的字母数量
        for (size_t i = 0; i < p.size(); i++)
        {
            count[p[i] - 'a']++;
        }

        for (size_t i = p.size() - 1; i < s.size(); i++)
        {
            // 拷贝数组
            vector<int> tmp(begin(count), end(count));
            // 检查当前遍历到的子串是否是异位词
            for (size_t j = i - p.size() + 1; j <= i; j++)
            {
                tmp[s[j] - 'a']--;
            }
            int k;
            for (k = 0; k < tmp.size(); k++)
            {
                // 不为0就不是异位词
                if (tmp[k] != 0)
                {
                    break;
                }
            }
            if (k == tmp.size())
            {
                ans.push_back(i - p.size() + 1);
            }
        }

        return ans;
    }
};
// @lc code=end
