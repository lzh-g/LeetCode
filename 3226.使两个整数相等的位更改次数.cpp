/*
 * @lc app=leetcode.cn id=3226 lang=cpp
 *
 * [3226] 使两个整数相等的位更改次数
 */
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minChanges(int n, int k)
    {
        int cnt = 0;
        while (n > 0 || k > 0)
        {
            // n有值为0的位且对应k的位为1，则无法变成相等
            if ((n & 1) == 0 && (k & 1) == 1)
            {
                return -1;
            }
            if ((n & 1) == 1 && (k & 1) == 0)
            {
                cnt++;
            }

            n >>= 1;
            k >>= 1;
        }
        return cnt;
    }
};
// @lc code=end
