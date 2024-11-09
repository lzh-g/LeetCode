/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // 思路：哈希表，数组也是一个哈希表，但是容量有限
        vector<int> count(26, 0);
        for (size_t i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }
        for (size_t i = 0; i < t.size(); i++)
        {
            count[t[i] - 'a']--;
        }

        for (size_t i = 0; i < count.size(); i++)
        {
            if (count[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
