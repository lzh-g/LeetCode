/*
 * @lc app=leetcode.cn id=1812 lang=cpp
 *
 * [1812] 判断国际象棋棋盘中一个格子的颜色
 */
#include <iostream>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool squareIsWhite(string coordinates)
    {
        return ((coordinates[0] - 'a') + (coordinates[1] - '0')) % 2 - 1;
    }
};
// @lc code=end
