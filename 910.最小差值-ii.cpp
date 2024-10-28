/*
 * @lc app=leetcode.cn id=910 lang=cpp
 *
 * [910] 最小差值 II
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        // 需要寻找一个分割点，分割点左侧全部+k，右侧全部-k
        // 这会导致+k的数中产生了新的最大值，或者-k的数中产生了新的最小值
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // 新的最小值是1~end的数-k后的数或者nums[0]+k的数
            int num_min = min(nums[i + 1] - k, nums[0] + k);
            // 新的最大值是0~end-1的数+k的数或者nums[end]-k的数
            int num_max = max(nums[i] + k, nums.back() - k);
            res = min(res, num_max - num_min);
        }
        return res;
    }
};
// @lc code=end
