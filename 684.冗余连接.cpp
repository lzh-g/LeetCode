/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int Find(vector<int> &parent, int node)
    {
        // 若当前的集合并不是自成一个集合的，就到他合并过去的集合里取找，最终同一合并到一个集合里
        if (parent[node] != node)
        {
            parent[node] = Find(parent, parent[node]);
        }
        return parent[node];
    }

    void Merge(vector<int> &parent, int node1, int node2)
    {
        // 找到node1所属的集合，将其合并到node2集合中去
        // parent[Find(parent, node1)] = parent[node2];
        parent[Find(parent, node2)] = parent[Find(parent, node1)];
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        // 并查集，处理不相交集合的合并问题，可以用来处理图的连通问题

        // 初始化并查集，初始状态每个顶点均属于各自的连通集合里
        vector<int> parent(edges.size() + 1);
        for (int i = 1; i <= edges.size(); i++)
        {
            parent[i] = i;
        }

        // 查找并查集，看边上的两点是否属于同一并查集，不属于则合并到一个并查集里，属于则为环
        for (auto &edge : edges)
        {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2))
            {
                Merge(parent, node1, node2);
            }
            else
            {
                return edge;
            }
        }
        return vector<int>();
    }
};
// @lc code=end
