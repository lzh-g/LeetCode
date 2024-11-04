/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
// @lc code=start
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long a = 0;
        long b = (int)sqrt(c);

        while (a <= b)
        {
            long res = a * a + b * b;
            if (res == c)
            {
                return true;
            }
            else if (res < c)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        return false;
    }
};
// @lc code=end
