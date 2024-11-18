/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size(), n = img[0].size();
        // 计算前缀和
        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i][j] + img[i][j];
            }
        }

        // 计算结果矩阵
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            int top = max(0, i - 1);
            int bottom = min(m, i + 2);
            for (int j = 0; j < n; j++)
            {
                int left = max(0, j - 1);
                int right = min(n, j + 2);
                int cnt = (bottom - top) * (right - left);
                res[i][j] = (preSum[bottom][right] - preSum[bottom][left] - preSum[top][right] + preSum[top][left]) / cnt;
            }
        }
        return res;
    }
};
// @lc code=end
