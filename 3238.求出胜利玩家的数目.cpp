/*
 * @lc app=leetcode.cn id=3238 lang=cpp
 *
 * [3238] 求出胜利玩家的数目
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        int res = 0;
        vector<vector<int>> color(n, vector<int>(11, 0));
        for (auto &&p : pick)
        {
            color[p[0]][p[1]]++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                if (color[i][j] > i)
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end