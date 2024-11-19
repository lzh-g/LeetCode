/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 *
 * [3243] 新增道路查询后的最短独立I
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        // prev[i]表示直接连向i的点集
        // dp[i]表示0-i的最短距离
        vector<vector<int>> prev(n);
        vector<int> dp(n);
        for (int i = 1; i < n; i++)
        {
            prev[i].push_back(i - 1);
            dp[i] = i;
        }

        vector<int> res;
        for (auto &&query : queries)
        {
            prev[query[1]].push_back(query[0]);
            // 每增加一条边，就更新一次dp数组
            for (int v = query[1]; v < n; v++)
            {
                // 遍历直接连向v的起点
                for (int u : prev[v])
                {
                    dp[v] = min(dp[v], dp[u] + 1);
                }
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};
// @lc code=end