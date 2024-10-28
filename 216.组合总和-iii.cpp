/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int n, int index, int sum)
    {
        if (sum > n)
        {
            return;
        }

        if (k == path.size() && sum == n)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);                  // 处理节点
            backtracking(k, n, i + 1, sum + i); // 递归
            path.pop_back();                    // 回溯
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        res.clear();
        path.clear();
        backtracking(k, n, 1, 0);
        return res;
    }
};
// @lc code=end
