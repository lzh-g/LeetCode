/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
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

    void backtracking(vector<int> &nums, int index)
    {
        res.push_back(path);

        for (int i = index; i < nums.size(); i++)
        {
            // nums[i]一定由nums[i-1]回溯而来，若相等，则表示重复
            if (i > index && nums[i] == nums[i - 1])
            {
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        res.clear();
        path.clear();
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
