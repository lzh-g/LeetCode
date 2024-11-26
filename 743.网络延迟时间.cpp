/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Dijkstra算法求单源最短路径长度
        const int inf = INT_MAX / 2;
        // 记录各点之间的最短距离，inf表示不可达
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &&time : times)
        {
            g[time[0] - 1][time[1] - 1] = time[2];
        }

        // 记录点k到其余各点的最短距离
        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        // 记录某一点是否遍历
        vector<int> used(n);
        for (int i = 0; i < n; i++)
        {
            int x = -1;
            for (int y = 0; y < n; y++)
            {
                if (!used[y] && (x == -1 || dist[y] < dist[x]))
                {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; y++)
            {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};
// @lc code=end
