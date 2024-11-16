/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        sort(nums.begin(), nums.end());
        unordered_set<int> set;
        int res = 0, cnt = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            // 仅该数字第一次出现才算
            if (set.count(nums[i] - 1) != 0 && set.count(nums[i]) == 0)
            {
                cnt++;
            }
            // 某个数第n次出现，不用管
            else if (set.count(nums[i]) != 0)
            {
                continue;
            }
            else
            {
                cnt = 1;
            }
            set.insert(nums[i]);
            res = max(res, cnt);
        }
        return res;
    }
};
// @lc code=end
