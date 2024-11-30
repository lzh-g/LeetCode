/*
 * @lc app=leetcode.cn id=3232 lang=cpp
 *
 * [3232] 判断是否可以赢得数字游戏
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int num : nums)
        {
            if (num >= 1 && num <= 9)
            {
                sum1 += num;
            }
            else if (num >= 10 && num <= 99)
            {
                sum2 += num;
            }
        }
        if (sum1 == sum2)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end