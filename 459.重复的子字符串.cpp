/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    void getNext(int *next, const string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++)
        {
            while (j >= 0 && s[i] != s[j + 1])
            {
                j = next[j];
            }
            if (s[i] == s[j + 1])
            {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s)
    {
        // 假设字符串s使用多个重复子串构成（这个子串是最小重复单位），重复出现的子字符串长度是x，所以s是由n *x组成。因为字符串s的最长相同前后缀的长度一定是不包含s本身，所以最长相同前后缀长度必然是m *x，而且 n - m = 1，所以如果 nx % (n - m) x = 0，就可以判定有重复出现的子字符串。
        if (s.size() == 0)
        {
            return false;
        }
        int next[s.size()];
        getNext(next, s);
        int len = s.size();

        if (next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0)
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
