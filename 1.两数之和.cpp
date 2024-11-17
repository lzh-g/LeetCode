/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end())
            {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end
