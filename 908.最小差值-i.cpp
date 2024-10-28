/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        if (res > 2 * k)
        {
            return res - 2 * k;
        }
        else
        {
            return 0;
        }
    }
};
// @lc code=end
