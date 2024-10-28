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
    void init(vector<int> &ancestor)
    {
        for (int i = 0; i < ancestor.size(); i++)
        {
            ancestor[i] = i;
        }
    }

    int find(vector<int> &ancestor, int node)
    {
        return ancestor[node] == node ? node : ancestor[node] = find(ancestor, ancestor[node]);
    }

    void Merge(vector<int> &ancestor, int node1, int node2)
    {
        ancestor[find(ancestor, node1)] = find(ancestor, node2);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> ancestor(n + 1);
        init(ancestor);

        int confilt = -1;
        int cycle = -1;
        for (int i = 0; i < n; i++)
        {
            auto edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if (ancestor[node2] != node2)
            {
                confilt = i;
            }
            else
            {
                ancestor[node2] = node1;
                if (find(ancestor, node1) == find(ancestor, node2))
                {
                    cycle = i;
                }
                else
                {
                    Merge(ancestor, node1, node2);
                }
            }
        }
        if (confilt < 0)
        {
            return vector<int>{edges[cycle][0], edges[cycle][1]};
        }
        else
        {
            auto confiltEdge = edges[confilt];
            if (cycle >= 0)
            {
                return vector<int>{ancestor[confiltEdge[1]], confiltEdge[1]};
            }
            else
            {
                return vector<int>{confiltEdge[0], confiltEdge[1]};
            }
        }
    }
};
// @lc code=end
