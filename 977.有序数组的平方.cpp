/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        int pos = nums.size() - 1;
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            if (nums[i] * nums[i] < nums[j] * nums[j])
            {
                ans[pos--] = nums[j] * nums[j];
                j--;
            }
            else
            {
                ans[pos--] = nums[i] * nums[i];
                i++;
            }
        }
        return ans;
    }
};
// @lc code=end
