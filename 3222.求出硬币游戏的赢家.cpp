/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */
#include <iostream>
#include <string>

using namespace std;
// @lc code=start
class Solution
{
public:
    string losingPlayer(int x, int y)
    {
        return min(x, y / 4) % 2 == 1 ? "Alice" : "Bob";
    }
};
// @lc code=end
