/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int index)
    {
        // 子集问题回溯和组合问题回溯不同，组合回溯收集的是树中叶子节点，子集问题收集的是树中各节点
        res.push_back(path);

        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracking(nums, 0);

        return res;
    }
};
// @lc code=end
