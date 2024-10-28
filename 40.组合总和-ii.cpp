/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
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
    // void backtracking(vector<int> &candidates, int target, int index, int sum, vector<bool> used)
    void backtracking(vector<int> &candidates, int target, int index, int sum)
    {
        if (sum == target)
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)
        {
            // 当前元素与前一个元素重复，但前一个元素未使用，则当前的组合重复，要跳过
            // if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false)
            // {
            //     continue;
            // }

            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }

            path.push_back(candidates[i]);
            // used[i] = true;
            // backtracking(candidates, target, i + 1, sum + candidates[i], used);
            backtracking(candidates, target, i + 1, sum + candidates[i]);
            path.pop_back();
            // used[i] = false;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // vector<bool> used(candidates.size(), false);
        res.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());
        // backtracking(candidates, target, 0, 0, used);
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
// @lc code=end
