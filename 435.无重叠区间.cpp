/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), cmp);
        // int overlap = 1;
        // for (int i = 1; i < intervals.size(); i++)
        // {
        //     if (intervals[i][0] >= intervals[i - 1][1])
        //     {
        //         overlap++;
        //     }
        //     else
        //     {
        //         intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
        //     }
        // }
        // return intervals.size() - overlap;

        int count = 0;
        int end = intervals[0][1]; // 区间分割点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= end)
            {
                end = intervals[i][1];
            }
            else
            {
                end = min(end, intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
