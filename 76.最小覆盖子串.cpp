/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    unordered_map<char, int> s_count, t_count;

    string minWindow(string s, string t)
    {
        int i = 0;
        int len = INT32_MAX;

        int ansL = -1;

        // 先获取t中的字符
        for (const auto it : t)
        {
            t_count[it]++;
        }

        for (int j = 0; j < s.size(); j++)
        {
            s_count[s[j]]++;
            // 如果当前遍历的元素在t中，放入s中
            if (t_count.find(s[j]) != t_count.end())
            {
                while (check() && i <= j)
                {
                    if (len > j - i + 1)
                    {
                        len = j - i + 1;
                        ansL = i;
                    }
                    s_count[s[i]]--;
                    i++;
                }
            }
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }

private:
    bool check()
    {
        for (const auto &it : t_count)
        {
            if (s_count[it.first] < it.second)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
