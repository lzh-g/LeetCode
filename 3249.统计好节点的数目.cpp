/*
 * @lc app=leetcode.cn id=3249 lang=cpp
 *
 * [3249] 统计好节点的数目
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int res;
    int countGoodNodes(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        res = 0;
        vector<vector<int>> g(n); // 邻接表
        // 初始化邻接表
        for (auto &&edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, g);
        return res;
    }

    int dfs(int node, int parent, vector<vector<int>> &g)
    {
        bool valid = true;
        int treeSize = 0;
        int subTreeSize = 0;

        for (auto &&child : g[node])
        {
            // 确保遍历顺序是从父节点->子节点
            if (child != parent)
            {
                int size = dfs(child, node, g);
                if (subTreeSize == 0)
                {
                    subTreeSize = size;
                }
                else if (size != subTreeSize)
                {
                    // 不满足好节点
                    valid = false;
                }
                treeSize += size;
            }
        }
        if (valid)
        {
            res++;
        }
        return treeSize + 1;
    }
};
// @lc code=end