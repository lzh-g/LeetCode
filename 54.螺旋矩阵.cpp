/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 先求出行数和列数
        int m = matrix.size();
        int n = matrix[0].size();

        if (m == 0 || n == 0 ||)
        {
            return {};
        }

        vector<int> ans;
        int count = 0;
        int left = 0, top = 0;
        int right = n - 1, bottom = m - 1;
        while (left <= right && top <= bottom)
        {
            // 右移
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            // 下移
            for (int j = top + 1; j <= bottom; j++)
            {
                ans.push_back(matrix[j][right]);
            }
            if (left < right && top < bottom)
            {
                // 左移
                for (int i = right - 1; i > left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                // 上移
                for (int j = bottom; j > top; j--)
                {
                    ans.push_back(matrix[j][left]);
                }
            }

            // 一圈之后，往里缩一层
            left++;
            top++;
            right--;
            bottom--;
        }
        return ans;
    }
};
// @lc code=end
