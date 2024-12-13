/*
 * @lc app=leetcode.cn id=3264 lang=cpp
 *
 * [3264] K次乘运算后的最终数组i
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        while (k--)
        {
            auto it = min_element(nums.begin(), nums.end());
            *it *= multiplier;
        }
        return nums;
    }
};
// @lc code=end