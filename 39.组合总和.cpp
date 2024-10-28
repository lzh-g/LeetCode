/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &candidates, int target, int index, int sum)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum + candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end
