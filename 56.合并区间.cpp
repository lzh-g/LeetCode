/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        // 先把第一个结果放进去
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            // 有重叠
            if (res.back()[1] >= intervals[i][0])
            {
                // 修改区间起止范围
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                // 没有重叠就直接放进去
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end
