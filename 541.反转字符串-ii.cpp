/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (int i = 0; i < s.size(); i += (2 * k))
        {
            // 如果剩余字符大于k个小于2k或等于2k
            if (i + k < s.size())
            {
                int left = i;
                int right = left + k - 1;
                while (left < right)
                {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
            }
            // 如果剩余字符小于k个
            else
            {
                int left = i;
                int right = s.size() - 1;
                while (left < right)
                {
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
            }
        }
        return s;
    }
};
// @lc code=end
