/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        // 先去除多余空格，反转整个字符串，再依次反转单词
        removespace(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int end = 0; end <= s.size(); end++)
        {
            if (s[end] == ' ' || end == s.size())
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }
        return s;
    }

    // 去除多余空格
    void removespace(string &s)
    {
        // 慢指针，某个单词的起始下标
        int slow = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                // 当前不是前导空格，就去掉空格
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                // 赋单词
                while (i < s.size() && s[i] != ' ')
                {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    // 反转函数
    void reverse(string &s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
// @lc code=end
