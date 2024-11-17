/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 使用前缀和存储0-i的和
        // nums[i]+pre[i-1]==pre[i]
        // pre[i]-pre[j-1]==k
        // 则pre[j-1]==pre[i]-k
        // 当遍历到j-1时，只要能找到pre[i]这个数，就表示有这个子数组
        unordered_map<int, int> mp;
        mp[0] = 1;
        int res = 0, pre = 0;
        for (auto &&num : nums)
        {
            pre += num;
            if (mp.find(pre - k) != mp.end())
            {
                res += mp[pre - k];
            }
            mp[pre]++;
        }
        return res;
    }
};
// @lc code=end
