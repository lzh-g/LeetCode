/*
 * @lc app=leetcode.cn id=2717 lang=cpp
 *
 * [2717] 半有序排列
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int semiOrderedPermutation(vector<int> &nums)
    {
        // 找到1和n，计算1到左，n到右的差，要考虑1和n的交换这一情况
        auto [first, last] = minmax_element(nums.begin(), nums.end());
        return first + nums.size() - last - 1 - (last < first);
    }
};
// @lc code=end
