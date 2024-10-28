/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        // 超时？
        int left = 1, right = num;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            if (num / middle == middle && num % middle == 0)
            {
                return true;
            }
            else if (num / middle > middle)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return false;
    }
};
// @lc code=end
