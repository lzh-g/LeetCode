/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int i = 0, j = height.size() - 1;
        while (i < j)
        {
            int Area = min(height[i], height[j]) * (j - i);
            res = max(res, Area);
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }
};
// @lc code=end
