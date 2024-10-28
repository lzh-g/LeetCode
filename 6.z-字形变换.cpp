/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
            return s;
        // 这里是一个string数组，分别表示每一行所需要存储的字符字串
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s)
        {
            rows[i].push_back(c);
            // 这里相当于切换方向
            if (i == 0 || i == numRows - 1)
                flag = -flag;
            i += flag;
        }
        string res;
        for (const string &row : rows)
            res += row;
        return res;
    }
};
// @lc code=end
