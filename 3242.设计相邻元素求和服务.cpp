/*
 * @lc app=leetcode.cn id=3242 lang=cpp
 *
 * [3242] 设计相邻元素求和服务
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
// @lc code=start
class NeighborSum
{
public:
    NeighborSum(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                m_pos[grid[i][j]] = {i, j};
            }
        }
        this->m_grid = move(grid);
    }

    int adjacentSum(int value)
    {
        return getSum(value, 0);
    }

    int diagonalSum(int value)
    {
        return getSum(value, 1);
    }

    int getSum(int value, int idx)
    {
        // 当前value的位置
        auto [x, y] = m_pos[value];
        int res = 0;
        for (int i = 0; i < 4; i++)
        {
            // 位置偏移
            int nx = x + dirs[idx][i][0];
            int ny = y + dirs[idx][i][1];

            // 偏移有效才加，越界偏移无效
            if (nx >= 0 && nx < m_grid.size() && ny >= 0 && ny < m_grid[0].size())
            {
                res += m_grid[nx][ny];
            }
        }
        return res;
    }

private:
    vector<vector<int>> m_grid;
    unordered_map<int, pair<int, int>> m_pos;
    static constexpr int dirs[2][4][2] = {
        {{-1, 0}, {1, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}}};
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end
