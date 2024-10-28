/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 使用一个标记矩阵
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2; // 圈数
        int i = 0, j = 0;
        int start_x = 0, start_y = 0;
        int offest = 1;
        int count = 1;
        while (loop--)
        {
            i = start_x;
            j = start_y;

            // 依次右、下、左、上
            for (; j < n - offest; j++)
            {
                res[i][j] = count++;
            }

            for (; i < n - offest; i++)
            {
                res[i][j] = count++;
            }

            for (; j > start_y; j--)
            {
                res[i][j] = count++;
            }

            for (; i > start_x; i--)
            {
                res[i][j] = count++;
            }

            // 一圈之后，下一圈的起始位置改变
            start_x++;
            start_y++;

            offest++;
        }

        // n为奇数，则中间会空一格
        if (n % 2 == 1)
        {
            res[n / 2][n / 2] = count;
        }

        return res;
    }
};
// @lc code=end
