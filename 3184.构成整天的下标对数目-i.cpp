/*
 * @lc app=leetcode.cn id=3184 lang=cpp
 *
 * [3184] 构成整天的下标对数目 I
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution
{
public:
    int countCompleteDayPairs(vector<int> &hours)
    {
        int res = 0;
        unordered_map<int, int> dict(24);
        for (int hour : hours)
        {
            res += dict[(24 - hour % 24) % 24];
            dict[hour % 24]++;
        }
        return res;
    }
};
// @lc code=end
