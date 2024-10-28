/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int s_count = transString(s);
        int t_count = transString(t);
        bool ans = true;
        // 情况1：转化后文本长度不同，一定不相等
        if (s_count != t_count)
        {
            ans = false;
        }
        for (size_t i = 0; i < s_count; i++)
        {
            if (s[i] != t[i])
            {
                ans = false;
            }
        }

        return ans;
    }

private:
    int transString(string &s)
    {
        int count = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s[i] == '#')
            {
                count -= 1;
                if (count < 0)
                {
                    count = 0;
                }
            }
            else
            {
                s[count++] = s[i];
            }
        }
        return count;
    }
};
// @lc code=end
