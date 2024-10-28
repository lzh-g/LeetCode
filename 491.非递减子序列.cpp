/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int index)
    {
        if (path.size() > 1)
        {
            res.push_back(path);
        }
        // unordered_set<int> used;
        int used[201] = {0};
        for (int i = index; i < nums.size(); i++)
        {
            if ((!path.empty() && nums[i] < path.back()) || (used[nums[i] + 100] != 0))
            {
                continue;
            }

            path.push_back(nums[i]);
            used[nums[i] + 100] = 1;
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
