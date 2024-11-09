/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        // 思路：统计每个字符串的字母数,mp的key-value结构为
        // "a1b2...z3":"str"，即key为各字母出现的次数，value为对应这种情况的所有字符串
        // 完成后，把mp转换成输出对应的格式
        unordered_map<string, vector<string>> mp;
        for (auto &it : strs)
        {
            vector<int> count(26, 0);
            // 对遍历到的字符串内字符计数
            for (size_t i = 0; i < it.size(); i++)
            {
                count[it[i] - 'a']++;
            }
            string key = "";
            for (size_t i = 0; i < 26; i++)
            {
                if (count[i] != 0)
                {
                    key.push_back(i + 'a');
                    key.push_back(count[i]);
                }
            }
            mp[key].push_back(it);
        }

        vector<vector<string>> ans;
        for (auto &it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};
// @lc code=end
