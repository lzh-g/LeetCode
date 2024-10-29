/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 *
 * [3211] 生成不含相邻零的二进制字符串
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> res;
    void backtracking(string str, int n)
    {
        if (str.size() == n)
        {
            res.push_back(str);
            return;
        }
        // 若字符串为空或当前末尾字符为1，则添加0或1，否则仅添加1
        if (str.size() == 0 || str.back() == '1')
        {
            str.push_back('0');
            backtracking(str, n);
            str.pop_back();
        }
        str.push_back('1');
        backtracking(str, n);
        str.pop_back();
    }
    vector<string> validStrings(int n)
    {
        res.clear();
        backtracking("", n);
        return res;
    }
};
// @lc code=end
