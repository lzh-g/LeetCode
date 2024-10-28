/*
 * @lc app=leetcode.cn id=3185 lang=cpp
 *
 * [3185] 构成整天的下标对数目 II
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    long long countCompleteDayPairs(vector<int> &hours)
    {
        long long res = 0;
        vector<int> cnt(24);
        for (int hour : hours)
        {
            res += cnt[(24 - hour % 24) % 24];
            cnt[hour % 24]++;
        }
        return res;
    }
};
// @lc code=end
