/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <vector>
#include <iostream>
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
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), cmp);
        int res = 1;
        for (int i = 1; i < points.size(); i++)
        {
            // 上一个球的end小于下一个球的start，那么一定要多用一支箭
            if (points[i][0] > points[i - 1][1])
            {
                res++;
            }
            else
            {
                // 更新为两个重叠球的最小end
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return res;
    }
};
// @lc code=end
