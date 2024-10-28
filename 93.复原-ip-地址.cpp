/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> res;
    bool isValid(const string &s, int start, int end)
    {
        if (start > end)
        {
            return false;
        }
        if (s[start] == '0' & start != end)
        {
            return false;
        }

        int sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255)
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string s, int index, int count)
    {
        if (count == 3)
        {
            if (isValid(s, index, s.size() - 1))
            {
                res.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (isValid(s, index, i))
            {
                s.insert(s.begin() + i + 1, '.'); // 直接操作s字符串
                backtracking(s, i + 2, count + 1);
                s.erase(s.begin() + i + 1); // 回溯
            }
            else
            {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
        {
            return res;
        }

        backtracking(s, 0, 0);
        return res;
    }
};
// @lc code=end
