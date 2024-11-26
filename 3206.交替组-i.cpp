/*
 * @lc app=leetcode.cn id=3206 lang=cpp
 *
 * [3206] 交替组 I
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors)
    {
        int res = 0;
        int n = colors.size();
        for (int i = 0; i < colors.size(); i++)
        {
            if (colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n])
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
