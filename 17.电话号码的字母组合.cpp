/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;
    void backtracking(string &digits, int index)
    {
        if (index == digits.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < phone[digits[index] - '0'].size(); i++)
        {
            path.push_back(phone[digits[index] - '0'][i]);
            backtracking(digits, index + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        path.clear();
        if (digits.size() == 0)
        {
            return res;
        }

        backtracking(digits, 0);
        return res;
    }
};
// @lc code=end
