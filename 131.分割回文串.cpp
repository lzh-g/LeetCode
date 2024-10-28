/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> isPalindrome;
    // bool isPalindrome(string s, int start, int end)
    // {
    //     while (start <= end)
    //     {
    //         if (s[start] != s[end])
    //         {
    //             return false;
    //         }
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    // void backtracking(string s, int index)
    // {
    //     if (index >= s.size())
    //     {
    //         res.push_back(path);
    //         return;
    //     }
    //     for (int i = index; i < s.size(); i++)
    //     {
    //         if (isPalindrome(s, index, i))
    //         {
    //             string str = s.substr(index, i - index + 1);
    //             path.push_back(str);
    //         }
    //         else
    //         {
    //             continue;
    //         }
    //         backtracking(s, i + 1);
    //         path.pop_back();
    //     }
    // }

    // 动规判断回文串
    void buildPalindrom(const string &s)
    {
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (i == j)
                {
                    isPalindrome[i][j] = true;
                }
                else if (j - i == 1)
                {
                    isPalindrome[i][j] = (s[i] == s[j]);
                }
                else
                {
                    isPalindrome[i][j] = (s[i] == s[j] && isPalindrome[i + 1][j - 1]);
                }
            }
        }
    }
    void backtracking(string s, int index)
    {
        if (index >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isPalindrome[index][i] == true)
            {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s)
    {
        res.clear();
        path.clear();
        buildPalindrom(s);
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end
