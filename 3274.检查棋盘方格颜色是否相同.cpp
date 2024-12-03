/*
 * @lc app=leetcode.cn id=3261 lang=cpp
 *
 * [3274] 检查棋盘放个颜色是否相同
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        int sum1 = 0, sum2 = 0;
        sum1 = static_cast<int>(coordinate1[0] - 'a') + static_cast<int>(coordinate1[1]);
        sum2 = static_cast<int>(coordinate2[0] - 'a') + static_cast<int>(coordinate2[1]);
        if (sum1 % 2 != sum2 % 2)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end