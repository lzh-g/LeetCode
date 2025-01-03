/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start

class Solution
{
public:
    vector<int> ancestor;

    void init(int n)
    {
        ancestor.resize(n);
        for (int i = 0; i < n; ++i)
        {
            ancestor[i] = i;
        }
    }

    int find(int index)
    {
        return index == ancestor[index] ? index : ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v)
    {
        ancestor[find(u)] = find(v);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        init(n + 1);
        auto parent = vector<int>(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            parent[i] = i;
        }
        int conflict = -1;
        int cycle = -1;
        for (int i = 0; i < n; ++i)
        {
            auto edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if (parent[node2] != node2)
            {
                conflict = i;
            }
            else
            {
                parent[node2] = node1;
                if (find(node1) == find(node2))
                {
                    cycle = i;
                }
                else
                {
                    merge(node1, node2);
                }
            }
        }
        if (conflict < 0)
        {
            auto redundant = vector<int>{edges[cycle][0], edges[cycle][1]};
            return redundant;
        }
        else
        {
            auto conflictEdge = edges[conflict];
            if (cycle >= 0)
            {
                auto redundant = vector<int>{parent[conflictEdge[1]], conflictEdge[1]};
                return redundant;
            }
            else
            {
                auto redundant = vector<int>{conflictEdge[0], conflictEdge[1]};
                return redundant;
            }
        }
    }
};
// @lc code=end
