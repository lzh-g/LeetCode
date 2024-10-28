/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path; // 存放当前遍历到的组合路径
    void backtracking(int n, int k, int Index)
    {
        if (path.size() == k) // 终止条件
        {
            res.push_back(path);
            return;
        }
        for (int i = Index; i <= n - (k - path.size()) + 1; i++)
        {
            path.push_back(i);         // 处理节点
            backtracking(n, k, i + 1); // 递归
            path.pop_back();           // 回溯
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        path.clear();

        backtracking(n, k, 1);
        return res;
    }
};
// @lc code=end
