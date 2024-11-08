/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为K的子数组能量I
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> results(n - k + 1, -1);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt = (i == 0) || (nums[i] - nums[i - 1]) == 1 ? cnt + 1 : 1;
            if (cnt >= k)
            {
                results[i - k + 1] = nums[i];
            }
        }

        return results;
    }
};
// @lc code=end