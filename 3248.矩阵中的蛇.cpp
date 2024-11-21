/*
 * @lc app=leetcode.cn id=3248 lang=cpp
 *
 * [3248] 矩阵中的蛇
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int res = 0;
        for (auto &&command : commands)
        {
            if (command == "UP")
            {
                res -= n;
            }
            else if (command == "RIGHT")
            {
                res += 1;
            }
            else if (command == "DOWN")
            {
                res += n;
            }
            else if (command == "LEFT")
            {
                res -= 1;
            }
        }
        return res;
    }
};
// @lc code=end