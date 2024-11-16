/*
 * @lc app=leetcode.cn id=3240 lang=cpp
 *
 * [3240] 最少翻转次数使二进制矩阵回文I
 */
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        // 分类讨论行和列，要保证行列均回文，则矩阵中某1个数对应了另外3个数要相等才能满足
        // 对于行和列数，若为奇数则需单独讨论
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                // 把1的数记下，看看是1->0的次数多还是0->1的次数多
                int cnt1 = grid[i][j] + grid[i][n - j - 1] + grid[m - i - 1][j] + grid[m - i - 1][n - j - 1];
                res += min(cnt1, 4 - cnt1);
            }
        }

        int diff = 0, cnt1 = 0;
        // 行数为奇
        if (m & 1)
        {
            for (int j = 0; j < n / 2; j++)
            {
                // 中间行的回文判断，如果不回文，则修改一次，若回文，要确保1的数量为4的倍数，则若为1则修改两次，若为0则不修改
                if (grid[m / 2][j] ^ grid[m / 2][n - j - 1])
                {
                    diff++;
                }
                else
                {
                    cnt1 += grid[m / 2][j] * 2;
                }
            }
        }
        // 列数为奇
        if (n & 1)
        {
            for (int i = 0; i < m / 2; i++)
            {
                if (grid[i][n / 2] ^ grid[m - i - 1][n / 2])
                {
                    diff++;
                }
                else
                {
                    cnt1 += grid[i][n / 2] * 2;
                }
            }
        }
        // 行列都为奇数，则中间必须为0
        if (m & 1 && n & 1)
        {
            res += grid[m / 2][n / 2];
        }

        if (diff > 0)
        {
            res += diff;
        }
        else
        {
            res += cnt1 % 4;
        }

        return res;
    }
};
// @lc code=end