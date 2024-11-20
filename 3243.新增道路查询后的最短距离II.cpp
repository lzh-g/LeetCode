/*
 * @lc app=leetcode.cn id=3243 lang=cpp
 *
 * [3243] 新增道路查询后的最短距离II
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        // roads[u]=v表示存在u->v的单向道路
        vector<int> roads(n);
        // 初始时，仅存在i->i+1的单向道路
        iota(roads.begin(), roads.end(), 1);
        vector<int> res;
        int dist = n - 1;
        for (auto &query : queries)
        {
            // 原先query[0]的单向道路
            int k = roads[query[0]];
            // 覆盖原先的query[0]单向道路
            roads[query[0]] = query[1];
            // 如果当前query[0]到达的点比新增的点小，则删除之间的道路，将新的道路加入
            while (k != -1 && k < query[1])
            {
                int t = roads[k];
                roads[k] = -1;
                k = t;
                dist--;
            }
            res.push_back(dist);
        }
        return res;
    }
};
// @lc code=end