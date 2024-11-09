/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // 双指针
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 排序后递增，第一个元素就大于0，那么肯定无法达到和为0
            if (nums[i] > 0 || nums[nums.size() - 1] < 0)
            {
                return res;
            }
            // 去重a
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 对b和c去重
                    while (right > left && nums[right] == nums[right - 1])
                    {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
