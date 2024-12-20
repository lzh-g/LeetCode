/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // 同15思路
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 剪枝
            if (nums[i] > target && nums[i] >= 0)
            {
                break;
            }

            // 对a去重
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                // 二次剪枝
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0)
                {
                    break;
                }

                // 对b去重
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        left++;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1])
                        {
                            right--;
                        }

                        left++;
                        right--;
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end
