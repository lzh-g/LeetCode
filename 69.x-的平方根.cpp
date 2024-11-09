/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <stdint.h>
// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x, ans = -1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if ((uint64_t)middle * middle <= x)
            {
                ans = middle;
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return ans;
    }
};
// @lc code=end
